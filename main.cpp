#include <iostream>
#include <fstream>


using namespace std;

int main() {
    string className;
    int n;

    cout << "Class name:"<< endl;
    cin >> className;
    cout << "Number of fields you want to create:"<<endl;
    cin >> n;
    cout << "Field names:"<<endl;
    string fieldNameTable [n];
    string fieldName;
    for (int i=0; i<n; i++){
        cin >> fieldName;
        fieldNameTable[i]=fieldName;
    }

    cout<<"Field types:"<<endl;
    string fieldTypeTable [n];
    string fieldType;
    for (int i=0; i<n; i++){
        cin >> fieldType;
        fieldTypeTable[i]=fieldType;
    }

    fstream cppFile;
    fstream hppFile;

    cppFile.open(className+".cpp", ios::out );
    hppFile.open(className+".h", ios::out);

    hppFile << "#pragma once"<<endl;
    hppFile << "using namespace std; "<< endl;
    hppFile << "#include <iostream> "<< endl;
    hppFile<< endl;
    hppFile <<"class "+className+"{";

    hppFile<<"public:"<<endl;
    hppFile<<className+"("<<endl;

    for(int i=0; i<n; i++) {
        hppFile<<fieldTypeTable[i]+" "+fieldNameTable[i]+",";
    }
    hppFile<<");"<<endl;

    for(int i=0; i<n; i++) {

        hppFile << "void set" + fieldNameTable[i] + "(" + fieldTypeTable[i] +" "+ fieldNameTable[i] + ");" << endl;
        hppFile << fieldTypeTable[i]+" get" + fieldNameTable[i] + "();" << endl;
    }


    hppFile<<"protected:"<<endl;
    for(int i=0; i<n; i++){
        hppFile<<fieldTypeTable[i]+" "+fieldNameTable[i]+";"<<endl;

    }
    hppFile<<"};"<<endl;

    cppFile<<"#inlcude "+ className + ".h\""<<endl;
    cppFile<<endl;
    for(int i=0; i<n; i++) {
        cppFile<<"void "+className+"::set"+fieldNameTable[i]+"("+fieldTypeTable[i]+" "+fieldNameTable[i]+"){"<<endl;
        cppFile<<className+"::"+fieldNameTable[i]+"="+fieldNameTable[i]+";"<<endl;
        cppFile<<"}"<<endl;

        cppFile << fieldTypeTable[i]+" "+className + "::get" + fieldNameTable[i]+"(){"<<endl;
        cppFile <<"return " + fieldNameTable[i]+";"<<endl;
        cppFile<<"}"<<endl;

    }
    cppFile<< endl;
    cppFile<<className+"::"+className+"(";
    for(int i=0; i<n; i++) {
        fieldTypeTable[i]+" "+fieldNameTable[i]+",";
    }
    cppFile<<") : ";
    for(int i=0; i<n; i++) {
        cppFile<< fieldNameTable[i]+"("+fieldNameTable[i]+"),";
    }
    cppFile<<"{}"<<endl;

    cppFile.close();
    hppFile.close();
    return 0;
}