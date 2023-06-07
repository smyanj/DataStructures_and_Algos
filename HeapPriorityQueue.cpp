#include <iostream>
//#include <queue>
#include <string>
#include <stdio.h>
using namespace std;

int key;
int time_elapsed;

class Node{
    public:
    string plane;
    int wait_time;
    Node* n_node;
    Node(string detail, int landing_time){
        plane = detail;
        wait_time = landing_time;
        //We want it to hit null if there aren't any planes available
        n_node = NULL;
    }
};
//allowing users to add plane data and wait time
Node *add_to_stack(Node *head, string name, int waiting){
    Node *p1 = new Node(name, waiting);
    if(head == NULL){
        p1->n_node = head;
        head = p1;
    }else if(head->wait_time > waiting){
        p1->n_node = head;
        head = p1;
    }else{
        Node *p2 = head;
        while(p2->n_node != NULL){
            if(p2->n_node->wait_time > waiting){
                p1->n_node = p2->n_node;
                p2->n_node = p1;
                break;
            }
            p2 = p2->n_node;
        }
        if(p2->n_node == NULL){
            p2->n_node = p1;
        }
    }
    return head;
}
//Displays all landing requests when #3 is pressed
void all_landing_req(Node *head){
    //cout<<"All active landing requests\n";
    if(head == NULL){
        cout<<"No requests made! \n";
        return;
    }
            Node *p1 = head;
            cout<<"All active landing requests\n";
            while(p1 != NULL){
                cout<<"Plane: "<<p1->plane<<"\nWaiting time: "<<p1->wait_time<<endl;
                p1 = p1->n_node;
            }
}

//Lands the plane at the front(head)
Node *land_plane(Node *head){
    if(head == NULL)
    cout<<"No planes available to land! \n";
    return NULL;

    string remove_plane = head->plane;
    int remove_wait = head->wait_time;
    cout<<"Plane "<<remove_plane<<" with a wait time of "<<remove_wait<<" has successfully landed"<<endl;
    head = head->n_node;
    return head;
}
int main(){
    //Selector for user input 
    Node *head = NULL;
    int user_req;
    int user_waittime;
    string plane_name;

    do{
        std::cout << "Welcome to the Plane Landing System\n";
        std::cout << "1. Make a landing request\n";
        std::cout << "2. Land a Plane\n";
        std::cout << "3. List all the landing requests\n";
        std::cout << "4. Exit\n";
        std::cout << "Select your option: ";
        std::cin >> user_req;
        
        switch(user_req){
            cout<<"Welcome to the Plane Landing System \n";
            
            case 1:
            cout<<"Plane Detail: ";
            cin>>plane_name;
            cout<<"Plane wait time: ";
            cin>>user_waittime;
            head = add_to_stack(head, plane_name, user_waittime);
            cout<<"Landing request completed successfully!\n\n";
            break;

            case 2:
            head = land_plane(head);
            break;

            case 3:
            //cout<<"All active landing requests\n";
            all_landing_req(head);
            break; 

            case 4:
            break;
        }
    }while (user_req != 4);
    
    return 0;
}
