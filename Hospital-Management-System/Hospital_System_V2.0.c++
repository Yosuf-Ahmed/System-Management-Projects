#include <iostream>
#include <string>
using namespace std;

#define SYSTEM_OPERATIONS 4
#define SPECIALIZATIONS 20
#define PATIENTS 5

string patients_name[SPECIALIZATIONS][PATIENTS];
int patient_status[SPECIALIZATIONS][PATIENTS];
int patient_counter[SPECIALIZATIONS] {0};



void menu(void){
    cout << "Enter your choice:" << endl;
    cout << "1) Add New Patient" << endl;
    cout << "2) Print All Patients" << endl;
    cout << "3) Get Next Patient" << endl;
    cout << "4) Exit" << endl;
}

bool Is_Avaliable(int specialization){
    if(patient_counter[specialization-1] < PATIENTS){
        return 1;
    }
    else{
        return 0;
    }
}


void Add_New_Patient(void){
    int specialization;
    int status;
    string name;

    cout << "Enter Specialization, Name, Status: ";
    cin >> specialization >> name >> status;
    if(!Is_Avaliable(specialization)){
        cout << "So Sorry, We can not Add More Patients for this Specialization !\n";
    }
    else{
        if(status == 0){
            patients_name[specialization-1][patient_counter[specialization-1]] = name;
            patient_status[specialization-1][patient_counter[specialization-1]] = status;
            patient_counter[specialization-1]++;
        }
        else{
            if(patient_counter[specialization-1]==0){
                patients_name[specialization-1][0] = name;
                patient_status[specialization-1][0] = status;
                patient_counter[specialization-1]++;
            }
            else{
                for(int i = patient_counter[specialization-1]; i > 0; i--){
                    patients_name[specialization-1][i] = patients_name[specialization-1][i-1];
                    patient_status[specialization-1][i] = patient_status[specialization-1][i-1];
                }
                patients_name[specialization-1][0] = name;
                patient_status[specialization-1][0] = status;
                patient_counter[specialization-1]++;

            }
        }
    }

    
}


void Print_All_Patients(void){
    for(int i=0; i<SPECIALIZATIONS; i++){
        if(patient_counter[i] != 0){
            cout << "There are " << patient_counter[i] << " patients in Specialization " << i+1 << endl;
            for(int j=0; j<patient_counter[i]; j++){
                cout << patients_name[i][j];
                if(patient_status[i][j]==0)
                   cout << " regular" << endl;
                else 
                   cout << " urgent" << endl; 
            }
            cout << endl;
        }
    }
}


void Get_Next_Patient(void){
    int specialization;
    cout << "Enter Specialization: ";
    cin >> specialization;

    if(patient_counter[specialization-1] == 0){
        cout << "No Patients at the moment, Have rest, Dr"<< endl;
    }
    else{
        cout << patients_name[specialization-1][0] << " Please go to with the Dr" << endl;
        if(patient_counter[specialization-1]==1){
            patient_counter[specialization-1]--;
        }
        else{
            for(int i=0; i<patient_counter[specialization-1]-1; i++){
                patients_name[specialization-1][i] = patients_name[specialization-1][i+1];
                patient_status[specialization-1][i] = patient_status[specialization-1][i+1];
            }
            patient_counter[specialization-1]--;
        }
    }
}







int main(void){

    while(1){
        int selected_choise;

        while (1)
        {
            menu();
            cin >> selected_choise;
            if(selected_choise > 0 && selected_choise <= SYSTEM_OPERATIONS)
                break;
            else{
                cout << "Invalid Choice, Please Try Again..." << endl;
            }
        
        }

        switch (selected_choise)
        {
        case 1:
            Add_New_Patient();
            break;
            
        case 2:

            cout << "***********************" << endl;
            Print_All_Patients();
            break;

        case 3:
            Get_Next_Patient();
            break;
        
        case 4:
            return 0;
        }
        

    }

}
