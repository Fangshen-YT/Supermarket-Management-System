// Name: add_goods_admin.h
// Author: �����
// Date: 2017-09-13
// Language: C
// Features: ���"��Ʒ���"���ܵ�ģ��.
// Modules:
//   - stdio.h
//   - string.h
//   - stdlib.h
//   - ctype.h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void log_out();
void check_information();
char new_shop_id[11];             // ����Ʒ���б�� 
char new_goods_id[11];            // ����Ʒ��Ʒ���
float new_unit_price;             // ����Ʒ���ۼ۸�
float new_in_price;               // ����Ʒ�����۸�
int new_sales_volume;             // ����Ʒ����
int new_goods_in_stock;           // ����Ʒ���
float new_discount_price;         // ����Ʒ�ۿۼ�
char new_discount_begin_time[25]; // ����Ʒ�ۿۿ�ʼʱ��
char new_discount_end_time[25];   // ����Ʒ�ۿ۽���ʱ�� 
		
typedef struct {
  char goods_id[11];            // ��Ʒ���
  float unit_price;             // ���ۼ۸�
  float in_price;               // �����۸�
  int sales_volume;             // ����
  int goods_in_stock;           // ���
  float discount_price;         // �ۿۼ�
  char discount_begin_time[25]; // �ۿۿ�ʼʱ��
  char discount_end_time[25];   // �ۿ۽���ʱ�� 
		
} STU_add_goods;


 STU_add_goods add_goods[100];
  int database_add_goods(char user_id[11]) {
  // ������ȡ�ļ�����ָ��
  FILE *fread;

  char file_name[300] =
      "/Users/zolar/OneDrive - Queen Mary, University of "
      "London/Project/Supermarket-Management-System/"
      "Supermarket-Management-System/database"; // ���ַ������ڴ����ļ���

  strcat(file_name, "/shop_index/"); // ����·��"/goods_information/"

  // �����ļ���
  strcat(file_name, user_id);
 
  // ���ض��Ķ��������ļ�
  if ((fread = fopen(file_name, "a+")) == NULL) // �ж��ļ��Ƿ���ڼ��ɶ�
  {
    printf("You have not sold anything.\n");
    return -1;
  }

  // ������Ʒ��Ϣ
  while(1){
    check_information();
   	 
    //��һ��ȷ����Ϣ 
     int op1;
     int op2;
     int i;
    do {
    printf("\n------------------------------\n");
    printf("1. ȷ�Ϸ�����Ʒ��Ϣ\n2. �����޸���Ʒ��Ϣ\n3. ȡ�������Ʒ��Ϣ\n");
    printf("�������Ӧ�������: ");
    scanf("%d", &op1);
    printf("\n------------------------------\n");
    switch (op1) {
    	
	case 1:
    fprintf(fread, "%s %f %f %d %d %f %s %s",
           new_goods_id,            // ��Ʒ���
           new_unit_price,          // ���ۼ۸�
           new_in_price,            // �����۸�
           new_sales_volume,        // ����
           new_goods_in_stock,      // ���
           new_discount_price,      // �ۿۼ�
           new_discount_begin_time, // �ۿۿ�ʼʱ��
           new_discount_end_time    // �ۿ۽���ʱ��
    );
    printf("�����Ʒ��Ϣ�ɹ�! \n");
    printf("�Ƿ���������Ʒ? \n"); 
    printf("1.��       2.��\n");
    do{
		printf("1.��       2.��\n");
		scanf("%d",&op2);
		printf("\n------------------------------\n");
		switch(op2){
			case 1:
			  break;
			case 2:
			  log_out();
			break;
			  default:
        	  printf("��������Ч������������! \n");        //������� 		
	          		}
       }while(1);
    
    
      break;
           
    case 2:
                  
      break;            //���»ص�������Ϣҳ��
      
    case 3:
      log_out();         //�����˳�ҳ��
      break;
      
    default:
      printf("��������Ч������������! \n"); //������� 
    
    }
  } while (1);
}
    	
 
  }



//�˳�ҳ��
void log_out() {
  printf("\n------------------------------\n");
  printf("��л�����ε�ʹ�ã��ټ�! ");
  printf("\n------------------------------\n");

  return;
}


//������Ϣ���ж��Ƿ���ȷ
void check_information() {

    printf("����������������Ʒ��Ϣ\n");
    
    
    printf("��Ʒ���: \n");                // ������Ʒ��Ų����� 
    scanf("%s",new_goods_id);
    
    
    	while(1)
	{
		int i=0;
		int n=1;
		int s,t;
		
		for(i=0;new_goods_id[i]!='\0';i++) 
		{
		  s=isalpha(new_goods_id[i]);
		  t=isdigit(new_goods_id[i]);
		  if(i==0||i==1) 
			{
				if(s==0)
				n=0;
			} 
		  else if(i==2||i==3||i==4||i==5) 
			{
				if(t==0)
				n=0;
			} 
	      else
			n=0;
		}
		
		if(i==6&&n==1)
		break;
		else
		{
		printf("���������Ʒ��Ų��Ϸ�������������: \n");
		scanf("%s",new_goods_id);
	    }
	}    
	
	
    int i = 0;                             
    while (!feof(fread)) {                     //�����Ʒ�Ƿ��ظ� 

    fscanf(fread, "%s %f %f %d %d %f %s %s",         // ��ȡ����
           add_goods[i].goods_id,                    // ��Ʒ���
           &add_goods[i].unit_price,                  // ����
           &add_goods[i].in_price,                    // ����
           &add_goods[i].sales_volume,                // ����
           &add_goods[i].goods_in_stock,              // ���
           &add_goods[i].discount_price,              // �ۿۼ�
           add_goods[i].discount_begin_time,         // �ۿۿ�ʼʱ��
           add_goods[i].discount_end_time            // �ۿ۽���ʱ��
    );
    
    if(add_goods[i].goods_id==new_goods_id){
   		printf("���������Ʒ�Ѿ����ڣ�����������: ");
    	scanf("%s",new_goods_id);
		i=-1;                                          //���¿�ʼѭ�� 
        }
    i++;
  }

    printf("���ۼ۸�: \n");            // ���뵥�۲����� 
    scanf("%f",new_unit_price);
         while (new_unit_price<=0)		 { 			
         printf("������ļ۸񲻺Ϸ�������������: ");
         scanf("%f",new_unit_price);        
		 }
    
    printf("�����۸�: \n");          // ������۲����� 
    scanf("%f",new_in_price);
         while (new_in_price<=0){			
         printf("������ļ۸񲻺Ϸ�������������: ");
         scanf("f",new_in_price);
 		 }
 		 
    printf("����: \n");                // �������������� 
    scanf("%d",&new_sales_volume);
    while (new_sales_volume<0){			
         printf("��������������Ϸ�������������: ");
         scanf("%d",&new_sales_volume);
         } 
         
    printf("���: \n");                 // ������������ 
    scanf("%d",&new_goods_in_stock);
         while (new_goods_in_stock<=0){			
         printf("������ļ۸񲻺Ϸ�������������: ");
         scanf("f",&new_goods_in_stock);
 		 }
    printf("�ۿۼ�: \n");               // �����ۿۼ۸񲢾��� 
    scanf("%f",new_discount_price);
         while (new_discount_price<=0){			
         printf("������ļ۸񲻺Ϸ�������������: ");
         scanf("%f",new_discount_price);
 		 }
    printf("�ۿۿ�ʼʱ��: \n");        // �����ۿۿ�ʼʱ�䲢���� 
    printf("�ۿ۽���ʱ��: \n");         // �����ۿ۽���ʱ�䲢���� 
}         

