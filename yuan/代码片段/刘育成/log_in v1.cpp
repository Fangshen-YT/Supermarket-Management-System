#include <stdio.h>
#include <string.h>
//���������û���Ҫ����Ĳ���
void log_in_admin();
void log_in_customer();
void exit();
int op;
int i = 0;
void log_in() {

  //��ӭҳ��
  printf("\n------------------------------\n\n");
  printf("��ӭʹ�����ϳ�����Ʒ����ϵͳ! ");
  printf("\n\n------------------------------\n");

  //ѭ��+ ѡ��
  do {
    printf("1. ����Աϵͳ\n2. ������ϵͳ\n3. �˳�\n");
    printf("�������Ӧ�������: ");
    scanf("%d", &op);
    printf("\n------------------------------\n");
    switch (op) {
    case 1:
      printf("��ӭ�������Աϵͳ! ");
      log_in_admin(); //�������Ա��¼ҳ��
      break;
    case 2:
      printf("��ӭ����������ϵͳ! ");
      log_in_customer(); //���������ߵ�¼ҳ��
      break;
    case 3:
      exit(); //�����˳�ҳ��
      break;
    default:
      printf("��������Ч������������!\n"); //������ѭ��
      i = 1;
    }
  } while (i == 1);
}

//����Ա��¼ҳ��
void log_in_admin() {
  char name[10];      //������û���
  char rname[10];     //��ȷ�û���
  char password[10];  //���������
  char rpassword[10]; //��ȷ����
  printf("\n�������û���: ");
  scanf("%s", &name);
  printf("����������: ");
  scanf("%s", &password);
  if ((strcmp(name, rname) == 0) &&
      (strcmp(password, rpassword) == 0)) //�ȶ��û����������Ƿ���ȷ
  {
    printf("\n��¼�ɹ�! ");

  } else {
    printf("\n�û������������! �����µ�½! ");
    log_in(); //���ó�ʼ��¼ҳ��
  }
}

//�����ߵ�¼ҳ��
void log_in_customer() {
  char cname[10];      //������û���
  char rcname[10];     //��ȷ�û���
  char cpassword[10];  //���������
  char rcpassword[10]; //��ȷ����
  printf("\n�������û���: ");
  scanf("%s", &cname);
  printf("����������: ");
  scanf("%s", &cpassword);
  if ((strcmp(cname, rcname) == 0) &&
      (strcmp(cpassword, rcpassword) == 0)) //�ȶ��û����������Ƿ���ȷ
  {
    printf("\n��¼�ɹ�! ");

  } else {
    printf("\n�û������������! �����µ�½! ");
    log_in(); //���ó�ʼ��¼ҳ��
  }
}

//�˳�ҳ��
void exit() {
  printf("\n------------------------------\n");
  printf("��л�����ε�ʹ�ã��ټ�! ");
  printf("\n------------------------------\n");

  return;
}

int main() { log_in(); }
