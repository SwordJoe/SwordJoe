#include"String.h"
#include<cstring>

char String::_nullchar = '\0';

String::String() : _pStr(new char[5] + 4){      //这里+5是为了最后留一个'\0'的位置
    cout<<"String()"<<endl;
    refCnt() = 1;
    _pStr[4] = '\0';
}

String::String(const char *str){
    cout<<"String(const char*)"<<endl;
    if(str != nullptr){
        _pStr = (new char[strlen(str)+5]) + 4;
        strcpy(_pStr, str);
        refCnt() = 1;       //引用计数置为1
    }
}


String::String(const String &rhs){
    cout<<"String::String(const String&)"<<endl;
    if(rhs._pStr){
        _pStr = rhs._pStr;
        ++refCnt();
    }
}

String& String::operator= (const String &rhs){
    cout<<"String& operator= (const String&)"<<endl;
    if(this != &rhs){
        -- *(int*)(_pStr - 4);
        if(refCnt() == 0){
            delete [](_pStr - 4);
        }
        _pStr = rhs._pStr;
        ++refCnt();
    }
    return *this;
}

ostream& operator<<(ostream& out, String &rhs){
    out<<rhs._pStr;
    return out;
}


String::~String(){
    cout<<"~String()"<<endl;
    if(_pStr){
        --refCnt();    //引用计数-1
        if( refCnt() == 0){
            delete [](_pStr - 4);
            _pStr = nullptr;
        }
    }
}

char& String::operator[](int idx){
    if(idx < size()){
        if(refCnt() > 1){
            char *tmpStr = new char[size() + 5] + 4;
            --refCnt();
            
            strcpy(tmpStr, _pStr);
            _pStr = tmpStr;
            refCnt() = 1;
        }
        return _pStr[idx];
    }
    else{
        return _nullchar;
    }
}