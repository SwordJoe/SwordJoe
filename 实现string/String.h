#pragma once

class String
{
public:
    String();
    String(const char* pStr);
    String(const String &rhs);
    String& operator= (const String &rhs);
    ~String();
    
    char operator[] (int idx) const;
    int size() const;
    char *c_str() const;
    
private:
    char *_pstr;
};