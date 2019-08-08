#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

typedef struct node_list
{
    string node_name;
    vector<string>& message;
}Node;

typedef struct message_list
{
    string message_name;
    vector<string>& signal;
}Message;

string lstrip(const string& tar,char temp=' ')
{
    string t=tar;
    while (true)
    {
        if (t[0]==temp && t.size()>1)
            t=t.substr(1,t.size());
        else if (t[0]==temp && t.size()==1)
        {
            t="";
            break;
        }
        else
            break;
    }
    return t;
}

//my split function
vector<string> split(const string& tar,char temp=' ')
{
    vector<string> res;
    string item;
    string tar_c=lstrip(tar,temp);
    for (int i=0;i<tar_c.size();i++)
    {
        if (tar_c[i]!=temp)
            item+=tar_c[i];
        else
        {
            res.push_back(item);
            item.clear();
        }
    }
    res.push_back(item);
    return res;
}

// string& rstrip(const string& tar,char temp=' ')
// {
//     while (true)
//     {
//         if (tar[tar.size()]==temp && tar.size()>1)
//             tar=tar.substr(0,tar.size()-1);
//         else if (tar[0]==temp && tar.size()==1)
//         {
//             tar="";
//             break;
//         }
//         else
//             break;
//     }
//     return tar;
// }


int main()
{
    ifstream fout;
    fout.open("C:\\Users\\wtr14\\Desktop\\code\\c++\\DBC_edit\\DBC_edit\\A39_II Project_ET1_CMX_DCU_V1.1.dbc");
    string temp;
    // vector <Node&> node;
    // vector <Message&> message;

    vector<string> node_name_list;
    vector <vector<string>> message_name_list,signal_name_list;
    vector<string> message_property,siganl_property;

    if (!fout.is_open())
    {
        cout<<"open failed"<<endl;
    }
    else
    {
        while (getline(fout,temp))
        {
            //½ÚµãÃû
            if (temp.find("BU_:")==0)
            {
                node_name_list=split(temp);
                cout<<"node name:"<<endl;
                node_name_list.erase(node_name_list.begin(),node_name_list.begin()+1); 
            }
            else if (temp.find("BO_ ")==0)
            {
                message_property=split(temp);
                message_property.erase(message_property.begin(),message_property.begin()+1);
                message_name_list.push_back(message_property);
            }
            else if (temp.find(" SG_ ")==0)
            {
                siganl_property=split(temp);
                siganl_property.erase(siganl_property.begin(),siganl_property.begin()+1);
                signal_name_list.push_back(siganl_property);
            }  
        }
        cout<<"hello";
    }
    system("pause");
    return 0;
}
