#include <fstream>
#include <map>
#include <memory>
#include <iostream>
#include <sstream>
#include "myExceptions.cpp"
#include <string>
#include <cstdlib>

using namespace std;

class field_base
{
public:
  virtual ~field_base() {}
  virtual void *data() = 0;
  virtual void display(ostream &os) const = 0;
};

template <class FieldType>
class field_impl : public field_base
{
  FieldType m_value;

public:
  field_impl(const FieldType &value) : m_value(value) {}

  ~field_impl() {}

  void *data()
  {
    return static_cast<void *>(&m_value);
  }

  void display(ostream &os) const
  {
    os << m_value;
  }
};

class field_storage
{
  std::map<std::string, std::unique_ptr<field_base>> m_fields;

public:
  field_storage() {}
  field_storage(const char *filename);
  bool read_file(const char *filename);

  template <class FieldType>
  FieldType &get(const std::string &field_name)
  {
    auto it = m_fields.find(field_name);
    if (it == m_fields.end())
    {
      throw field_missing_error(field_name);
    }
    auto raw_field_ptr = it->second.get();
    auto field_ptr = static_cast<field_impl<FieldType> *>(raw_field_ptr);
    if (dynamic_cast<field_impl<FieldType> *>(raw_field_ptr) == nullptr)
    {
      throw field_type_mismatch_error(field_name, typeid(FieldType).name(), typeid(raw_field_ptr).name());
    }
    return *static_cast<FieldType *>(field_ptr->data());
  }

  friend std::ostream &operator<<(std::ostream &os, const field_storage &fields);

private:
  void parse_line(const std::string &line);
  field_base *parse_value(const std::string &value);
};

field_storage::field_storage(const char *filename)
{
  read_file(filename);
}

void field_storage::parse_line(const std::string &line)
{
  auto colon_pos = line.find(':');
  if (colon_pos == string::npos)
  {
    throw field_file_format_error();
  }

  auto field_name = line.substr(0, colon_pos);
  auto field_value = line.substr(colon_pos + 1);

  if (m_fields.find(field_name) != m_fields.end())
  {
    throw field_file_format_error();
  }

  if (auto field = parse_value(field_value))
  {
    m_fields[field_name] = std::unique_ptr<field_base>(field);
  }
}

field_base *field_storage::parse_value(const std::string &value)
{
  if (value == "true")
  {
    return new field_impl<bool>(true);
  }
  if (value == "false")
  {
    return new field_impl<bool>(false);
  }

  auto last_char_pos = value.size() - 1;
  if (value[0] == '\"' && value[last_char_pos] == '\"')
  {
    auto string_value = value.substr(1, value.size() - 2);
    return new field_impl<std::string>(string_value);
  }

  stringstream ss(value);
  int int_value;
  ss >> int_value;
  if (ss.fail())
  {
    throw field_file_format_error();
  }
  return new field_impl<int>(int_value);
}

bool field_storage::read_file(const char *filename)
{
  ifstream input_stream(filename);

  if (input_stream.fail())
  {
    throw field_file_missing(filename);
  }

  int line = 0;
  try
  {
    while (!input_stream.eof())
    {
      line++;
      string current_line;
      getline(input_stream, current_line);
      if (current_line.size() == 0)
        continue;
      parse_line(current_line);
    }
  }
  catch (const field_file_format_error &error)
  {
    throw field_file_format_error(filename, line);
  }
  return true;
}

std::ostream &operator<<(std::ostream &os, const field_storage &fields)
{
  for (const auto &pair : fields.m_fields)
  {
    os << pair.first << ": ";
    pair.second->display(os);
    os << endl;
  }
  return os;
}

// g++ exceptions.cpp -o main && ./main.exe

int main(int argc, char **argv)
{
  field_storage storage("fields.txt");

  // 2.1
  try
  {
    field_storage e("nera.txt");
  }
  catch (const exception &ex)
  {
    cout << ex.what() << endl;
  }

  // 2.2
  try
  {
    field_storage e("nocolon.txt");
  }
  catch (const exception &ex)
  {
    cout << ex.what() << endl;
  }
  // 2.3
  try
  {
    field_storage e("incorrectValue.txt");
  }
  catch (const exception &ex)
  {
    cout << ex.what() << endl;
  }
  // 2.4
  try
  {
    field_storage e("2names.txt");
  }
  catch (const exception &ex)
  {
    cout << ex.what() << endl;
  }
  // 2.5
  try
  {
    auto invalid = storage.get<int>("xxass");
  }
  catch (const exception &ex)
  {
    cout << ex.what() << endl;
  }
  // 2.6
  try
  {
    auto invalid = storage.get<int>("bool1");
  }
  catch (const exception &ex)
  {
    cout << ex.what() << endl;
  }
}
