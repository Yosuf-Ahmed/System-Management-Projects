#include <iostream>
#include <string>
#define MAX_PATIENTS 5
#define MAX_SPECIALIZATIONS 21
#define MAX_SYSTEM_OPERATION 5
using namespace std;



struct patients{
    string P_name;
    int P_status;
};


struct Patients_Queue{
    patients Specialization_Queue[MAX_PATIENTS];

    int pointer =0;

    void Add_to_front(string name, int status){
        if(pointer == 0){
            Specialization_Queue[pointer].P_name = name;
            Specialization_Queue[pointer].P_status = status;
            pointer++;
        }else{
            for(int i=pointer; i>0; i--){
                Specialization_Queue[i] = Specialization_Queue[i-1];
            }
            Specialization_Queue[0].P_name = name;
            Specialization_Queue[0].P_status = status;
            pointer++;
        }
    }

    void Add_to_end(string name, int status){
       /* if(pointer == MAX_PATIENTS){
            cout << "Sory, We cant't add more patients for this specialization " << endl;
        }
        else{*/
            Specialization_Queue[pointer].P_name = name;
            Specialization_Queue[pointer].P_status = status;
            pointer++;
        //}
    }

    void add_patient(){
        if(pointer == MAX_PATIENTS){
            cout << "Sory, We cant't add more patients for this specialization " << endl;
        }
        else{
        string name;
        int status;
        cout << "Enter The patient name, status: " ;
        cin >> name >> status;
        if(status == 0){
            Add_to_end(name, status);
        }else{
            Add_to_front(name, status);
        }
    }

    }

    void Print_specialization_Queue(void){
        if(pointer == 0){
            cout << "This Specialization is Empty" << endl;
        }else{
            cout << "There are " << pointer << " Pateint(s) in this spectialization" << endl;
            for(int i=0; i<pointer; i++){
                cout << Specialization_Queue[i].P_name ;
                if(Specialization_Queue[i].P_status == 0){
                    cout << " regular" << endl;
                }else{
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


void print_all_patients(void){
    cout << "\n================================\n\n";
    for(int i=1; i<MAX_SPECIALIZATIONS; i++){
        cout << "\n";
        cout << "Specialization " << i << " :" << endl;
        Hospital_System[i].Print_specialization_Queue();
        cout << "\n================================\n";
    }
    
}


void menu(void){
    cout << "1) Add New Patient" << endl;
    cout << "2) Print Patients of Spectialization " << endl;
    cout << "3) Print All Patients" << endl;
    cout << "4) Get Next patient" << endl;
    cout << "5) Exit" << endl;
    cout << "Enter your choice: ";
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
            while(true){
                cout << "Enter Specialization: ";
                cin >> selected_specialization;
                if(selected_specialization >0 && selected_specialization < MAX_SPECIALIZATIONS){
                    break;
                }else{
                    cout << "Invalid Specialization, please try again ... " << endl;
                }
            }
            Hospital_System[selected_specialization].add_patient();
            break;
        case 2:
            while(true){
                cout << "Enter Specialization: ";
                cin >> selected_specialization;
                if(selected_specialization > 0 && selected_specialization < MAX_SPECIALIZATIONS){
                    break;
                }else{
                    cout << "Invalid Specialization, please try again ... " << endl;
                } 
            }
            Hospital_System[selected_specialization].Print_specialization_Queue();
            break;
        case 3:
            print_all_patients();
            break;
        case 4:
            while(true){
                cout << "Enter Specialization: ";
                cin >> selected_specialization;
                if(selected_specialization > 0 && selected_specialization < MAX_SPECIALIZATIONS){
                    break;
                }else{
                    cout << "Invalid Specialization, Please try again ... " << endl;
                }
            }
            Hospital_System[selected_specialization].pickup_patient();
            break;
        case 5:
            while(true){
                char Make_sure;
                cout << "Are you sure you want to go out?" << endl;
                cout << "Enter (Y)/(N) : ";
                cin >> Make_sure;
                if(Make_sure == 'Y' || Make_sure == 'y'){
                    break;
                }else if(Make_sure == 'N' || Make_sure == 'n'){
                    cout << "go out, and re enter again "<< endl;
                    break;
                }else{
                    cout << "Invalid choice, please try again ... " << endl;
                }
            }
            return 0;

        }
        
    }
}