#include <iostream>

using namespace std;

class field_file_missing : public exception
{
protected:
    string fileName;

public:
    field_file_missing(string fileName) : fileName(fileName){};
    const char *what() const noexcept
    {
        string *msg = new string("File not found: " + fileName);
        return msg->c_str();
    };
};

class field_file_format_error : public exception
{
protected:
    string fileName;
    int line;

public:
    field_file_format_error(){};
    field_file_format_error(string fileName, int line) : fileName(fileName), line(line){};
    const char *what() const noexcept
    {
        string *msgError = new string("File format_error: " + fileName + " line: " + to_string(line));
        return msgError->c_str();
    };
};

class field_missing_error : public exception
{
protected:
    string field;

public:
    field_missing_error() {}
    field_missing_error(string field) : field(field) {}
    const char *what() const noexcept
    {
        string *msgError = new string("Field not found: " + field);
        return msgError->c_str();
    }
};

class field_type_mismatch_error : public exception
{
protected:
    string field;
    string searched;
    string realType;

public:
    field_type_mismatch_error() {}
    field_type_mismatch_error(string field, string searched, string realType) : field(field), searched(searched), realType(realType) {}
    const char *what() const noexcept
    {
        string *msgError = new string("Field type mismatch: " + field + " searched for: " + searched + " but it is: " + realType);
        return msgError->c_str();
    }
};