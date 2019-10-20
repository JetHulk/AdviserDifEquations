// Programmer: Aleksandra Sukhodolskaia


using namespace std;
#include <iostream>
#include <fstream>
#include <utility>

#include "Node.h"
#include "newNode.h"

void askQuestion(struct Node* node);
Node* fileFillTree();
Node* fileFill(ifstream &file);

int main()
{
    //create the binary tree and initialize it using the function that returns a pointer to that tree
    struct Node *root = fileFillTree();

    cout << "Type Y (yes) or N (no) to the question to define your DE.\n";
    askQuestion(root);

    getchar();
    return 0;
}

//Function that asks the user questions taking them from the binary tree
//decides which way to go on the branches depending on the user's answer
void askQuestion(struct Node* node){

//variable that hold the answer (yes/no)
    char answer;

//since we get the root which is the initial question that is always asked
    cout << node->data << endl;

//we check if the next nodes are empty and if so, then it signals the end of the tree
//then we end the function and return to main
    if(node->right==nullptr && node->left == nullptr)
        return;

//get the answer
    cin >> answer;

    //choosing the case (yse, no)
    switch(answer){
        //moves to the left branch
        case 'Y': askQuestion(node->left);
            break;
            //moves to the right branch
        case 'N': askQuestion(node->right);
            break;
        default:
            cout << "Error! Switch!\n";
    }
}

//The recursive function that fills the binary tree while taking
//texts from the text file
Node* fileFill(ifstream &file) {

    //the string that captures the file text initially
    string buff;

    getline(file, buff);

    //checks if we read empty line, if so then returns nullptr
    if (buff.empty()) {
        return nullptr;
    }
    //creates a new node and assigns the gotten information
    struct Node *node = newNode(buff);

    node->left = fileFill(file);
    node->right = fileFill(file);
    return node;
}

//the function that calls recursie function ones and
//open and close the text file.
Node* fileFillTree(){

    struct Node *root = nullptr;

    //opens the output file
    ifstream file;
    file.open("../DE.txt");

    //checks if it's opened
    //if not, then system is stopped
    if(!file.is_open()){

        cout << "File does not exist.\n";
        exit(1); //call system to stop
    }else{
        root = fileFill(file);
    }

    //file is closed
    file.close();

    return root;
}