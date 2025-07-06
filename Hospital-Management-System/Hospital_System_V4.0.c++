#include <iostream>
#include <string>
#define MAX_PATIENTS 5
#define MAX_SPECIALIZATIONS 21
#define MAX_SYSTEM_OPERATION 4
using namespace std;



struct patients{
    string P_name;
    int P_status;
};


struct Patients_Queue{
    patients Specialization_Queue[MAX_PATIENTS];

    int pointer =0;

    void add_patient(){
        if(pointer == MAX_PATIENTS){
            cout << "Sory, We cant't add more patients for this spitialization " << endl;
        }
        else{
            string name;
            int status;
            cout << "Enter The patient name, status: " ;
            cin >> name >> status;
            if(status == 0){
                Specialization_Queue[pointer].P_name = name;
                Specialization_Queue[pointer].P_status = status;
                pointer++;
            }else{
                if(pointer == 0){
                    Specialization_Queue[pointer].P_name = name;
                    Specialization_Queue[pointer].P_status = status;
                    pointer++;
                }
                else{
                    for(int i=pointer; i>0; i--){
                        Specialization_Queue[i] = Specialization_Queue[i-1];
                    }
                    Specialization_Queue[0].P_name = name;
                    Specialization_Queue[0].P_status = status;
                    pointer++;
                }
            }
        }
    }


    void print_specialization_Queue(void){
        if(pointer == 0){
            cout << "This Specialization is Empty" << endl;
        }
        else{
        cout << "There are " << pointer << " patient(s) in this Specialization" << endl;
        for(int i=0; i<pointer; i++){
            cout << Specialization_Queue[i].P_name ;
            if(Specialization_Queue[i].P_status == 0){
                cout << " regular" << endl;
            }
            else{
                cout << " urgent" << endl;
            }
        }
    }
    }

    void pickup_patient(void){
        if(pointer == 0){
            cout << "No patients at the moment take rest DR " << endl;
        }
        else{
            cout << Specialization_Queue[0].P_name << " please go with the Docotr " << endl;
            for(int i=0; i<pointer-1; i++){
                Specialization_Queue[i].P_name = Specialization_Queue[i+1].P_name;
                Specialization_Queue[i].P_status = Specialization_Queue[i+1].P_status;
            }
            pointer--;
        }
    }
};

Patients_Queue Hospital_System[MAX_SPECIALIZATIONS];


void menu(void){
    cout << "Enter your choice:" << endl;
    cout << "1) Add New Patient" << endl;
    cout << "2) Print All Patients" << endl;
    cout << "3) Get Next Patient" << endl;
    cout << "4) Exit" << endl;
}



int main(void){
    int selected_operation;
    int selected_specialization;

    while(true){
        while(true){
            menu();
           cin >> selected_operation;
           if(selected_operation >0 && selected_operation <=MAX_SYSTEM_OPERATION){
            break;
           }else{
            cout << "Invalid Choise  Please try again ... " << endl;
           }
        }
        switch (selected_operation)
        {
        case 1:
            cout << "Enter Specialization: ";
            cin >> selected_specialization;
            Hospital_System[selected_specialization].add_patient();
            break;
        
        case 2:
            cout << "Enter Specialization: ";
            cin >> selected_specialization;
            Hospital_System[selected_specialization].print_specialization_Queue();
            break;
        case 3:
            cout << "Enter Specialization: ";
            cin >> selected_specialization;
            Hospital_System[selected_specialization].pickup_patient();
            break;
        case 4:
            return 0;

        }
        
    }
}