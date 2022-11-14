#include <iostream>
#include <string>
#include <cctype>
#include <cstdio>
#include <cstdlib>
using namespace std;


bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)   
        if (isdigit(str[i]) == false) {
            if(str[i] == '.' || str[i] == ' ' )continue;
        return false;
    }    
    return true;
}

//https://www.tutorialspoint.com/cplusplus-program-to-check-if-input-is-an-integer-or-a-string#:~:text=Apply%20isdigit()%20function%20that,the%20value%20of%20type%20int.


string lowercases(string strlwr){

    string lower;
    for (int i = 0; i < strlwr.length(); i++) {
        lower += char(tolower(strlwr[i]));
    }
    return lower;
}

void invalid_input(string inputno,string invalid_area,int costumer_no, string value, string allowedvalues){
    cout << " [UNEXPECTED INPUT] "<< inputno << ":" << invalid_area <<" = \""<< value  << "\"\n\t     Only "<< allowedvalues <<" VALUES are Allowed" << endl;
    cout << "Please Repeat All the information for Costumer #" << costumer_no << endl;
}


bool checking_User_Input(string no_of_Cart_Items,string preferred_Packaging, string number_of_boxes,string preferred_Payment_Method,string e_or_n, int no){

    if(check_number(no_of_Cart_Items) == false) {
        invalid_input("1st input","No of Cart items",no,no_of_Cart_Items, "\"NUMERICAL\"");
        return true;
    }
  
    if(!(preferred_Packaging == "box" || preferred_Packaging == "bag")) { 
        invalid_input("2nd input","Preferred Packaging",no,preferred_Packaging, "\"Box\" or \"Bag\"");
        return true;
    }
    if(check_number(number_of_boxes) == false){
        invalid_input("3rd input","Number of Boxes",no,number_of_boxes, "\"NUMERICAL\"");
        return true;
    }
    if (!(preferred_Payment_Method == "cash" || preferred_Payment_Method == "digital")) {
        invalid_input("4th input","Preferred Payment Method",no,preferred_Payment_Method, "\"Cash\" or \"Digital\"");
        return true;
        }
    if(preferred_Payment_Method == "cash"){
        if(!(e_or_n == "e" || e_or_n == "ne")){ 
            invalid_input("5th input","Exact Cash or Not Exact Casho",no,e_or_n, "\"e\" for Exact Cash or \"ne\" for Not Exact Cash");
            return true;
        }
    }
    return false;
}

class Customer {
  private:
    double no_of_Cart_Items;
    string preferred_Packaging;
    double number_of_boxes;
    string preferred_Payment_Method;
    string exact_or_not_cash;
    double idle;

// Setting a costumers information
  public:
    void set_no_of_Cart_Items(int no_of_Cart_Items) {
      this->no_of_Cart_Items = no_of_Cart_Items;
    }
    void set_preferred_Packaging(string preferred_Packaging) {
      this->preferred_Packaging = preferred_Packaging;
    }
    void set_number_of_boxes(int number_of_boxes) {
      this->number_of_boxes = number_of_boxes;
    }
    void set_preferred_Payment_Method(string preferred_Payment_Method) {
      this->preferred_Payment_Method = preferred_Payment_Method;
    }
    void set_exact_or_not_cash(string exact_or_not_cash) {
      this->exact_or_not_cash = exact_or_not_cash;
    }
    void set_idle(double idle) {
      this->idle = idle;
    }

    // Get the infomation about costumer individually

    double get_no_of_Cart_Items(){
        return this->no_of_Cart_Items ;
    }
    double get_number_of_boxes(){
        return this->number_of_boxes;
    }
    double get_idle(){
        return this->idle;
    }
    string get_preferred_Packaging(){
        return this->preferred_Packaging;
    }
    string get_preferred_Payment_Method(){
        return this->preferred_Payment_Method;
    }
    string get_exact_or_not_cash(){
        return this-> exact_or_not_cash;
    }

    //computation of time
    double get_decarting_time(){
        return this->no_of_Cart_Items * 0.5;
    }
    double get_scanning_time(){
        return this->no_of_Cart_Items  * 0.5;
    }
    double get_packing_time(){
        if(this->preferred_Packaging == "bag") {
            return (((this->no_of_Cart_Items) * 0.5) + ((this->number_of_boxes) * 5));
        }else{
            return (((this->no_of_Cart_Items) * 0.5) + ((this->number_of_boxes) * 10));
        }
    }
    double get_paying_time(){
         if(this->preferred_Payment_Method == "cash" ){
            if (exact_or_not_cash == "e"){
                return 15;
            } else{
                return 20;
            }
        }else{
            return 15;
        }
    }
    double get_receipt_printing_time(){
        return ((this->no_of_Cart_Items) * 0.3) + 2.0;
    }
    double get_customer_qeueu_time(){
        return (get_decarting_time() + get_scanning_time() ) + get_packing_time() + get_paying_time() + get_receipt_printing_time() + idle;
    }
};

int main() {
    int no_of_Customer;
    double lane_Queue;
    cin >> no_of_Customer;
    Customer list_of_Customer[no_of_Customer];
   

    for (int i = 0; i < no_of_Customer; i++)
    {
        string no_of_Cart_Items;
        string preferred_Packaging;
        string number_of_boxes;
        string preferred_Payment_Method;
        string e_or_n;

        do{
            cin >> no_of_Cart_Items;
            cin >> preferred_Packaging;
            cin >> number_of_boxes;
            cin >> preferred_Payment_Method;
            preferred_Payment_Method = lowercases(preferred_Payment_Method);
            if(preferred_Payment_Method == "cash"){
                cin >> e_or_n;
                e_or_n = lowercases(e_or_n);
            }
            preferred_Packaging = lowercases(preferred_Packaging);

        }while(checking_User_Input(no_of_Cart_Items ,preferred_Packaging, number_of_boxes, preferred_Payment_Method ,e_or_n , i+1) == true );

    
        list_of_Customer[i].set_no_of_Cart_Items(stod(no_of_Cart_Items));
        list_of_Customer[i].set_preferred_Packaging(preferred_Packaging);
        list_of_Customer[i].set_number_of_boxes(stod(number_of_boxes));
        list_of_Customer[i].set_preferred_Payment_Method(preferred_Payment_Method);
        if(preferred_Payment_Method == "cash"){
            list_of_Customer[i].set_exact_or_not_cash(e_or_n);
        }
        list_of_Customer[i].set_idle((i > 0 ? 3 : 0));

    }

        cout << "==============================================" << endl;
        
        for (int i = 0; i < no_of_Customer; i++)
        {

            
            cout << "Costumer #" << i+1 << ".:" << endl;
            cout << "no of cart: "<< list_of_Customer[i].get_no_of_Cart_Items() << endl;
            cout << "preferred packaging: "<< list_of_Customer[i].get_preferred_Packaging() << endl;
            cout << "no of package "<< list_of_Customer[i].get_preferred_Packaging() << ":"<< list_of_Customer[i].get_number_of_boxes()  << endl;
            cout << "payment method: " << list_of_Customer[i].get_preferred_Payment_Method();
            if(list_of_Customer[i].get_exact_or_not_cash() == "e"){
                cout << "(Exact)"; 
            }else if (list_of_Customer[i].get_exact_or_not_cash() == "ne")
            {
                cout << "(Not Exact)"; 
            }

            cout << "\n+++++++++++++++++++++++++++++++++++++++++++" << endl;

            cout << "Total De-Carting Time:" << list_of_Customer[i].get_decarting_time() << endl;
            cout << "Total Scanning Time:"<< list_of_Customer[i].get_scanning_time() << endl;
            cout << "Total Packing Time:" << list_of_Customer[i].get_packing_time()  << endl;
            cout << "Total Paying Time:" << list_of_Customer[i].get_paying_time() <<  endl;
            cout << "Idle Time:" << list_of_Customer[i].get_idle() << endl;
            cout << "Total Receipt Printing Time:"<< list_of_Customer[i].get_receipt_printing_time() << endl;
            cout << "Total Customer-Queue Time:"<< list_of_Customer[i].get_customer_qeueu_time() << endl;

            lane_Queue += list_of_Customer[i].get_customer_qeueu_time();
            if(i+1 !=  no_of_Customer) cout << "--------------------------------------------" << endl;
            
        }
     cout << "====================================" << endl;
    
     cout << "Total Lane Queue Time: " << lane_Queue;

    return 0;
}