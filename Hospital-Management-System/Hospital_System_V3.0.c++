#include <iostream>
#include <string>
#define SYSTEM_OPERATIONS 4
#define Specializations 20
#define Pateins 5
using namespace std;

struct Patient{
    string name;
    int status;
};
Patient Hospital_data_base[Specializations][Pateins];
int added[Specializations] = {0};

void menu(void){
    cout << "Enter your choice:" << endl;
    cout << "1) Add New Patient" << endl;
    cout << "2) Print All Patients" << endl;
    cout << "3) Get Next Patient" << endl;
    cout << "4) Exit" << endl;
}

bool Is_Avaliable(int special){
    if(added[special-1]<Pateins){
        return 1;
    }
    else{
        return 0;
    }
}

void Add_New_Patient(){
    string P_name;
    int P_status;
    int P_spicial;
    cout << "Enter Specialization, Name, Status: ";
    cin >> P_spicial >> P_name >> P_status;
    if(! Is_Avaliable(P_spicial)){
        cout << "So Sorry, We can not Add More Patients for this Specialization !\n";
    }
    else{
        if(P_status == 0){
            Hospital_data_base[P_spicial-1][added[P_spicial-1]].name = P_name;
            Hospital_data_base[P_spicial-1][added[P_spicial-1]].status = P_status;
            added[P_spicial-1]++;
        }
        else{
            if(added[P_spicial]==0){
                Hospital_data_base[P_spicial-1][0].name = P_name;
                Hospital_data_base[P_spicial-1][0].status = P_status;
                added[P_spicial-1]++;
            }
            else{
                for(int i=added[P_spicial-1]; i>0; i--){
                    Hospital_data_base[P_spicial-1][i] = Hospital_data_base[P_spicial-1][i-1];
                }
                Hospital_data_base[P_spicial-1][0].name = P_name;
                Hospital_data_base[P_spicial-1][0].status = P_status;
                added[P_spicial-1]++;
            }
        }
    }
    

}

void Print_All_Patients(void){
    for(int i =0; i<Specializations; i++){
        if(added[i] != 0){
            cout << "There are " << added[i] << " patients in Specialization " << i+1 << endl;
            for(int j=0; j<added[i]; j++){
                cout << Hospital_data_base[i][j].name;
                if(Hospital_data_base[i][j].status==0)
                   cout << " regular" << endl;
                else 
                   cout << " urgent" << endl; 
            }
            cout << endl;
        }
    }
}

void Get_Next_Patient(){
    int speci;
    cout << "Enter Specialization : ";
    cin >> speci;
    if(added[speci-1] == 0){
        cout << "No Patients at the moment, Have rest, Dr"<< endl;
    }
    else{
        if(added[speci-1]==1){
            added[speci-1]--;
        }
        else{
        cout << Hospital_data_base[speci-1][0].name  << " Please go to with the Dr" << endl;
        for(int i=0; i<added[speci]-1; i++){
            Hospital_data_base[speci-1][i] = Hospital_data_base[speci-1][i+1];
        }
        added[speci-1]--;
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
