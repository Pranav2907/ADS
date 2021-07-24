#include<iostream>
#include<queue>
#include<stack>
#define SPACE 10

using namespace std;

class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
  bool isLeaf(){
  	return left== NULL ? right == NULL : false;
  }
  
};

class BST {
  public:
    TreeNode * root;
  BST() {
    root = NULL;
  }
  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }

 
  	TreeNode* insertRecursive(TreeNode *r, TreeNode *new_node)// 1.) function
	{
		if(r==NULL)
		{
			r=new_node;
			cout <<"Insertion successful"<<endl;
			return r;
		}
	
		if(new_node->value < r->value)
		{
			r->left = insertRecursive(r->left,new_node);
		}
		else if (new_node->value > r->value)  
		{
			r->right = insertRecursive(r->right,new_node);
		}
	   else
	   {
	     	cout << "No duplicate values allowed!" << endl;
	     	return r; 
		}
		return r;
	}

  void print2D(TreeNode * r, int space) {    // 2.) function
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }
  
  int depth(TreeNode * r) {   //6.) depth of tree
    if (r == NULL)
      return -1;
    queue<TreeNode *> q;
    q.push(r);
    int depth = 0;
    while (1)
    {
    	int nodeCount = q.size();
    	if (nodeCount == 0)
    	   return depth;
    	depth++;
		
		while (nodeCount > 0)
		{
		    TreeNode *tmp = q.front();
			q.pop();
			if(tmp->left != NULL)
			{
				q.push(tmp->left);
			}
			if(tmp->right != NULL)
			{
				q.push(tmp->right);
			}
			nodeCount--;
				 
	    }
	}
  }
  void MirrorTree(TreeNode* r)//7.) function
  {
    
	if (r==NULL)
	  return;
	queue<TreeNode*> q;
	q.push(r);
	while(!q.empty())
	{
		TreeNode* t = q.front();
		q.pop();
		swap(t->left,t->right);
		if (t->left)
		  q.push(t->left);
		if (t->right)
		  q.push(t->right);  
	  }  
	

  }
  void printLeafNodes(TreeNode* r)  //8.) function
  {
  	 if(r==NULL)
  	  {
  	  return;
	 }
	 stack<TreeNode *> s;
     s.push(r);
     while(!s.empty())
     {
     	TreeNode*tmp =  s.top();
     	s.pop();
     	if(tmp->left !=NULL)
     	{
     		s.push(tmp->left);
		 }
		 if(tmp->right !=NULL)
		 {
		 	s.push(tmp->right);
		 }
		 if(tmp->isLeaf()){
		 	cout<<tmp->value<<endl;
		 }
	 }
     
  }
  
  void printPreorder(TreeNode * r) //3)function
  {
    if (r == NULL)
      return;
    /* first print data of node */
    cout << r -> value << " ";
    /* then recur on left sutree */
    printPreorder(r -> left);
    /* now recur on right subtree */
    printPreorder(r -> right);
    //The code is written by Pranav Gaikwad 2195041
  }
  
  void printInorder(TreeNode * r) //  5)function
  {
    if (r == NULL)
      return;
    /* first recur on left child */
    printInorder(r -> left);
    /* the code is written by pranav gaikwad 2195041 */
    cout << r -> value << " ";
    /* now recur on right child */
    printInorder(r -> right);
  }
  
  void printPostorder(TreeNode * r) //4.) function
  {
    if (r == NULL)
      return;
    // first recur on left subtree 
    printPostorder(r -> left);
    // then recur on right subtree 
    printPostorder(r -> right);
    // now deal with the node 
    cout << r -> value << " ";
  }
    TreeNode * iterativeSearch(int v) {
    if (root == NULL) {
      return root;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (v == temp -> value) {
          return temp;
        } else if (v < temp -> value) {
          temp = temp -> left;
        } else {
          temp = temp -> right;
        }
      }
      return NULL;
    }
  }


 

  

};

int main() {
  BST obj , obj1;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Print 2D" << endl;
    cout << "3. Pre-Order Traversal" << endl;
    cout << "4. Post-Order Traversal" << endl;
    cout << "5. In-Order Traversal"<<endl;
    cout << "6. Depdth of Tree" << endl;
    cout << "7. Mirror Tree " << endl;
    cout << "8. Leaf Nodes" <<endl;
    cout << "9. Clear Screen" << endl;
    cout << "10. Search" <<endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    TreeNode * new_node = new TreeNode();

    switch (option) {
    case 0:
      break;
    case 1:
      	cout <<"INSERT"<<endl;
	      cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
	      cin >> val;
	      new_node->value = val;
	      obj.root= obj.insertRecursive(obj.root,new_node);
	      //obj.insertNode(new_node);
	      cout<<endl;
    		break;
      
    case 2:
        cout << "PRINT 2D: " << endl;
        obj.print2D(obj.root, 5);
        break;
    case 3:
      cout << "Pre-Order Travesal" << endl;
      obj.printPreorder(obj.root);
      cout<<endl;
      
      break;
    case 4:
      cout << "Post-order Traversal " << endl;
      obj.printPostorder(obj.root);
      cout<<endl;
      
     
      break;
    case 5:
      cout << "In-order Traversal" << endl;
      obj.printInorder(obj.root);
      cout<<endl;
      
      break;
    case 6:
      cout <<"Depth of the Tree"<<endl;
      cout << "depth : " << obj.depth(obj.root) << endl;
      break;
    case 7:
	  cout <<"Mirror Tree"<<endl;
	  obj.MirrorTree(obj.root);
	  cout<<"Mirrored Sucessfully"<<endl;
	  break;
	case 8:
	  cout<<"Leaf Nodes"<<endl;
	  obj.printLeafNodes(obj.root);
	  break;
	case 9:
	   system("cls"); 
	case 10:
	    cout << "SEARCH" << endl;
        cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
        cin >> val;
         new_node = obj.iterativeSearch(val);
       
       if (new_node != NULL) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;       
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}


