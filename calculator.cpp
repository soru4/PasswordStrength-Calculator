#include <iostream>
#include <string>
#include <cctype>
#include <cmath>

using namespace std; 

int main(){
    string password; 

    cout << "Enter your password: " <<endl;

    cin >> password; 

    bool foundLower = false; 
    bool foundUpper = false; 
    bool foundNum = false;
    bool foundSpecial = false; 
    int chars = 0; 
    for(int i = 0; i < password.length(); i++){
        if(islower(password[i]) && !foundLower){
            chars += 24;
            foundLower  = true;
        }
        if(isupper(password[i]) && !foundUpper){
            chars += 24;
            foundUpper  = true;
        }
        if(isdigit(password[i]) && !foundNum){
            chars += 10; 
            foundNum = true; 
        }if(!(isalnum(password[i]) || isdigit(password[i]) || isspace(password[i])) && !foundSpecial){
            chars += 32;
            foundSpecial = true;
        }

    }

    // calculate entropy. 
    double entropy = chars * log2(password.length()); 
    if(entropy < 40){
        cout << "Your password with " << entropy << " bits of entropy is very weak. " << endl;  
    }else if( entropy < 50){
        cout << "Your password with " << entropy << " bits of entropy is weak. " << endl;  
    }
    else if( entropy < 70){
        cout << "Your password with " << entropy << " bits of entropy is of average strength. " << endl;  
    }else if( entropy < 90){
        cout << "Your password with " << entropy << " bits of entropy is slightly strong. " << endl;  
    }else if(entropy < 100){
        cout << "Your password with " << entropy << " bits of entropy is strong. " << endl;  

    }else if(entropy >100){
        cout << "Your password with " << entropy << " bits of entropy is very strong. " << endl;  

    }
    long double time = pow(2, entropy) / pow(10,11); 
    double years  = time/ (60*60*24*365);

    cout << "your password will take " << years << " years to brute force the hash." <<endl;

}
