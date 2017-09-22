#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ṹ������Ʒ��������
typedef struct {
  char store[20];    // ��Ʒ���
  char name[20];     // ��������
  char email[20];    // Ӫҵ��
  char password[20]; // ����
} STU_admin_information;

STU_admin_information admin_information;
char file_name_global[300];

void database_admin_information(char user_id[11]) {
  // ������ȡ�ļ�����ָ��
  FILE *fread;

  char file_name[300] =
      "/Users/zolar/OneDrive - Queen Mary, University of "
      "London/Project/Supermarket-Management-System/"
      "Supermarket-Management-System/database"; // ���ַ������ڴ����ļ���

  strcat(file_name, "/admin_information/"); // ����·��"admin_information/"

  // �����ļ���
  strcat(file_name, user_id);
  strcat(file_name, ".txt");

  // ���ض��Ķ��������ļ�
  fread = fopen(file_name, "r");

  fscanf(fread, "%s %s %s %s", admin_information.store, admin_information.name,
         admin_information.email, admin_information.password);

  fclose(fread);

  strcpy(file_name_global, file_name);
  return; // ���涩������
}

int check_email(char email[20]) {
  int i, j = 0, k = 0, n = 0, m = 0, temp = 0;
  for (i = 0; i < strlen(email); i++) {
    if (email[i] == '@')
      j++, n = i;
  }
  for (i = 0; i < strlen(email); i++) {
    if (email[i] == '.')
      k++, m = i;
  }
  if (k == 1 && j == 1)
    temp++;
  if (n + 1 < m)
    temp++;
  return temp;
}

void changes_admin_password(char user_id[11]) {
  FILE *fp;

  database_admin_information(user_id); // ���ݿ⴫��file_name_global
  printf("\n�������µ��˻�����: ");
  scanf("%s", admin_information.password);
  fp = fopen(file_name_global, "w+");
  fprintf(fp, "%s %s %s %s", admin_information.store, admin_information.name,
          admin_information.email, admin_information.password);
  fclose(fp);
  printf("\n�޸ĳɹ�! ");
  return;
}



void changes_admin_email(char user_id[11]) {
	FILE *fp;
    database_admin_information(user_id); // ���ݿ⴫��file_name
  printf("\n�������µ�����: ");
  int i;
  scanf("%s",admin_information.email);
  i = check_email(admin_information.email);
  while (i != 2) {
    printf("\n�����ʽ����, �������������! ");
    printf("\n"); 
    memset(admin_information.email, 0, sizeof(admin_information.email));
   scanf("%s",admin_information.email);
    i = check_email(admin_information.email);
  }

  fp = fopen(file_name_global, "w+");
  fprintf(fp, "%s %s %s %s", admin_information.store, admin_information.name,
          admin_information.email, admin_information.password);
  fclose(fp);
  printf("\n�޸ĳɹ�! ");
  return;
}

void changes_admin(char user_id[11]) {
  int temp=1; 
  int choose;
  do {
    printf("1. �޸��˻�����\n2. �޸�����");
    printf("\n�������Ӧ�������: ");
    printf("\n------------------------------");
    printf("\n");
    scanf("%d", &choose);
    switch (choose) {
    case 1:
      printf("\n�������޸��˻�����! ");
      changes_admin_password(user_id);
      break;
    case 2:
      printf("\n�������޸�����! ");
      changes_admin_email(user_id);
      break;
    default:
      printf("\n������ı����Ч���������������! ");
      printf("\n"); 
      temp = 0;
    }
  } while (temp == 0);

  return;
}

int main() {

  char user_id[11] = "ZY2017";
  changes_admin(user_id);
  return 0;
}

