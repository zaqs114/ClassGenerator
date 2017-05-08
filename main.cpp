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
    for (int i=0; i<n; i++){
        cin >> fieldNameTable[i];
    }

    cout<<"Field types:"<<endl;
    string fieldTypeTable [n];
    for (int i=0; i<n; i++){
        cin >> fieldTypeTable[i];
    }

    fstream cppFile;
    fstream hppFile;

    cppFile.open(className+".cpp", ios::out );
    hppFile.open(className+".h", ios::out);

    //hpp
    hppFile << "#pragma once"<<endl;
    hppFile << "using namespace std; "<< endl;
    hppFile << "#include <iostream> "<< endl;
    hppFile<< endl;
    hppFile <<"class "+className+"{"<<endl;

    //public
    hppFile<<"public:"<<endl;
    //constructor
    hppFile<<"\t"+className+"();"<<endl;
    hppFile<<"\t"+className+"(";

    for(int i=0; i<n; i++) {
        if(i==n-1){
            hppFile << fieldTypeTable[i] + " " + fieldNameTable[i];
        }else {
            hppFile << fieldTypeTable[i] + " " + fieldNameTable[i] + ",";
        }
    }
    hppFile<<");"<<endl;

    //getters and setters
    for(int i=0; i<n; i++) {

        hppFile << "\tvoid set" + fieldNameTable[i] + "(" + fieldTypeTable[i] +" "+ fieldNameTable[i] + ");" << endl;
        hppFile << "\t"+fieldTypeTable[i]+" get" + fieldNameTable[i] + "();" << endl;
    }

    //variables
    hppFile<<"protected:"<<endl;
    for(int i=0; i<n; i++){
        hppFile<<"\t"+fieldTypeTable[i]+" "+fieldNameTable[i]+";"<<endl;

    }
    hppFile<<"};"<<endl;

    //cpp
    cppFile<<"#include \""+ className + ".h\""<<endl;
    cppFile<<endl;
    //getters and setters
    for(int i=0; i<n; i++) {
        cppFile<<"void "+className+"::set"+fieldNameTable[i]+"("+fieldTypeTable[i]+" "+fieldNameTable[i]+"){"<<endl;
        cppFile<<"\t"+className+"::"+fieldNameTable[i]+"="+fieldNameTable[i]+";"<<endl;
        cppFile<<"}"<<endl;
        cppFile<<endl;

        cppFile << fieldTypeTable[i]+" "+className + "::get" + fieldNameTable[i]+"(){"<<endl;
        cppFile <<"\treturn " + fieldNameTable[i]+";"<<endl;
        cppFile<<"}"<<endl;
        cppFile<<endl;
    }
    cppFile<< endl;

    //constructor
    cppFile<<className+"::"+className+"(";
    for(int i=0; i<n; i++) {
        if(i==n-1){
            cppFile<< fieldTypeTable[i]+" "+fieldNameTable[i];
        }else {
            cppFile << fieldTypeTable[i] + " " + fieldNameTable[i] + ", ";
        }
    }
    cppFile<<"){"<<endl;
    for (int i=0; i<n; i++) {
        cppFile << "set" +fieldNameTable[i]+"("+fieldNameTable[i]+");"<<endl;
    }
    cppFile<<"}"<<endl;

    cppFile.close();
    hppFile.close();
    return 0;
}
