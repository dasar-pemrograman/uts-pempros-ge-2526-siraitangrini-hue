#include <stdio.h>
#include <string.h>

int main() {} 
int main() { 
    char input[256];
#include <stdlib.h>

#define MAX_ITEM 1000
#define MAX_LOG 10000
} 

typedef struct{
    char id[50];
    char name[100];
    int quantity;
    double price;
}Item;

typedef struct{
    int log_id;
    char item_id[50];
    char type[20];
    int quantity;
}Log;

Item items[MAX_ITEM];
Log logs[MAX_LOG];

int itemCount=0;
int logCount=0;
int globalLogID=1;
int findItem(char *id){

    for(int i=0;i<itemCount;i++){

        if(strcmp(items[i].id,id)==0)
            return i;
    }

    return -1;
}

void addLog(char *id,char *type,int qty){

    logs[logCount].log_id=globalLogID;
    strcpy(logs[logCount].item_id,id);
    strcpy(logs[logCount].type,type);
    logs[logCount].quantity=qty;

}

while(fgets(input,sizeof(input),stdin)){

input[strcspn(input,"\n")]=0;

if(strcmp(input,"---")==0)
    break;

char *cmd=strtok(input,"#");

if(cmd==NULL)
    continue;

if(strcmp(cmd,"receive")==0){

char *id=strtok(NULL,"#");
char *name=strtok(NULL,"#");
char *qtyStr=strtok(NULL,"#");
char *priceStr=strtok(NULL,"#");

if(id==NULL||name==NULL||qtyStr==NULL||priceStr==NULL)
    continue;

int qty=atoi(qtyStr);
double price=atof(priceStr);
if(qty<=0)
    continue;

if(findItem(id)!=-1)
    continue;

strcpy(items[itemCount].id,id);
strcpy(items[itemCount].name,name);
items[itemCount].quantity=qty;
items[itemCount].price=price;

itemCount++;

addLog(id,"receive",qty);

}

else if(strcmp(cmd,"ship")==0){

char *id=strtok(NULL,"#");
char *qtyStr=strtok(NULL,"#");

if(id==NULL||qtyStr==NULL)
    continue;

int qty=atoi(qtyStr);

if(qty<=0)
    continue;

int index=findItem(id);

if(index==-1)
    continue;

if(items[index].quantity<qty)
    continue;

items[index].quantity-=qty;

addLog(id,"ship",qty);

}

else if(strcmp(cmd,"restock")==0){

char *id=strtok(NULL,"#");
char *qtyStr=strtok(NULL,"#");

if(id==NULL||qtyStr==NULL)
    continue;

int qty=atoi(qtyStr);

if(qty<=0)
    continue;

int index=findItem(id);

if(index==-1)
    continue;

items[index].quantity+=qty;

addLog(id,"restock",qty);

}

else if(strcmp(cmd,"report")==0){

for(int i=0;i<itemCount;i++){

printf("%s|%s|%d|%.1f\n",
items[i].id,
items[i].name,
items[i].quantity,
items[i].price);

}

else if(strcmp(cmd,"audit")==0){

char *id=strtok(NULL,"#");

if(id==NULL)
    continue;

int index=findItem(id);

if(index==-1)
    continue;

printf("%s|%s|%d|%.1f\n",
items[index].id,
items[index].name,
items[index].quantity,
items[index].price);

for(int i=0;i<logCount;i++){

if(strcmp(logs[i].item_id,id)==0){

printf("%d|%s|%d\n",
logs[i].log_id,
logs[i].type,
logs[i].quantity);

}

}

}

}

return 0;

}
    while (fgets(input, sizeof(input), stdin)) {
        if (strncmp(input, "---", 3) == 0) {
            break;
        }

        // TODO: implement logic
    }

    return 0;
}