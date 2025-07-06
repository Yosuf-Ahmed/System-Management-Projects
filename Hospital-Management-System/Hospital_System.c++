#include <iostream>
#include<string>
using namespace std;
#define MAX_SPECIALIZATIONS 20
#define MAX_PATIENTS 5

string patient_Data[MAX_SPECIALIZATIONS][MAX_PATIENTS];
int patient_counter[20] = {};

void pickUp_patient(void){
    int Specialization;
    cout << "Enter Specialization: ";
    cin >> Specialization;

    if(patient_counter[Specialization-1]==0){
        cout << "No Patients at the moment, Have rest, Dr"<< endl;
    }
    else{
        cout << patient_Data[Specialization-1][0] <<  " Please go to with the Dr" << endl;
        for(int i=1; i<=patient_counter[Specialization-1]-1; i++){
            patient_Data[Specialization-1][i-1]=patient_Data[Specialization-1][i];
        }
        patient_counter[Specialization-1]--;
    }
}
void show_menu(void){
    cout << "Enter your choice: " << endl;
    cout << "1) Add New patient" << endl;
    cout << "2) Print All Patients" << endl;
    cout << "3) Get Next Patient" << endl;
    cout << "4) Exit" << endl;
}

void  Print_All_Patients(void){
    for(int i=0; i<MAX_SPECIALIZATIONS; i++){
        if(patient_counter[i]!=0){
            cout << "There are " << patient_counter[i] << " patients in Specialization " << i+1 << endl;
            for(int j=0; j<=patient_counter[i]-1; j++){
                cout << patient_Data[i][j] << endl;
            }
            cout << endl;
        }
        
    }
}

bool Is_Available(int specialization){
    if(patient_counter[specialization-1] < MAX_PATIENTS){
        return 1;
    }
    else{
        return 0;
    }
}


void Add_Patient(void){
    int specialization;
    string patient_name;
    int patient_status;
    cout << "Enter Name, Specialization, Status: ";
    cin >> patient_name >> specialization >> patient_status;
    if(Is_Available(specialization)){
        if(patient_status == 0){
        patient_Data[specialization-1][patient_counter[specialization-1]] = patient_name;
        patient_counter[specialization-1]++;
    }
        else if(patient_status==1){
            for(int i=patient_counter[specialization-1]-1; i>=0; i--){
                patient_Data[specialization-1][i+1]=patient_Data[specialization-1][i];
            }
            patient_Data[specialization-1][0] = patient_name;
            patient_counter[specialization-1]++;
        }
    }
    else{
        cout << "SO Sorry, We can not Add More Patients for this Specialization !\n";
    }
    

}








int main(void){
    while (true)
    {
        int selected_operation;
        show_menu();
        cin >> selected_operation;
        cout << "*****************************\n";

        switch (selected_operation)
        {
        case 1:
            Add_Patient();
            break;
        
        case 2:
            Print_All_Patients();
            break;
        case 3:
            pickUp_patient();
            break;
        case 4:
            return 0;
        }
        

    }
        
}