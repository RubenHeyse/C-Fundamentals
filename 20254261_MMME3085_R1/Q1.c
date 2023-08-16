#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

struct employee
  {
    char name[50];
    int hours[12];
    double total_salary;
  };

double GetWeeklyPay(double, int);
void DisplayEmployee(struct employee);
void SaveEmployeeData(FILE **fptr, struct employee employee){

  if(fptr == NULL)
  {
    printf("Error!");   
    exit(1);             
  }

  int total_hours = 0;
  for (int i = 0 ; i<12; i++){
    total_hours += employee.hours[i];
  }

  fprintf(*fptr,"Employee Name: %s\n", employee.name);
  fprintf(*fptr,"Total hours worked: %i\n", total_hours);
  fprintf(*fptr,"Total salary: %.2f\n", employee.total_salary);
}

int main( int argc, char *argv[] ) {

  char wages_fname[30];
  char output_fname[30];
  printf("Enter filename for wages: ");
  gets(wages_fname);
  printf("Enter filename for output file: ");
  gets(output_fname);

/*#########################

    Open output file

#########################*/
  char cwd[200];
  char out_filepath[200];
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    strcat(cwd, "\\");
    strcat(cwd, output_fname);
  } else {
    perror("getcwd() error");
    return 1;
  }

  strcpy(out_filepath, cwd);
  
  FILE *fptr;

  if ((fptr = fopen(cwd,"r")) == NULL){
    printf("Error! opening file");
    // Program exits if the file pointer returns NULL.
    exit(1);
  }
  fclose(fptr);
/*#########################

    Open wages file

#########################*/
  if (getcwd(cwd, sizeof(cwd)) != NULL) {
    strcat(cwd, "\\");
    strcat(cwd, wages_fname);
  } else {
    perror("getcwd() error");
    return 1;
  }
  
  if ((fptr = fopen(cwd,"r")) == NULL){
    printf("Error! opening file");
    // Program exits if the file pointer returns NULL.
    exit(1);
  }

  int line_length = 100;
  char file_line[line_length];
  int first_line_flag = 0;
  double hourly_rate;
  int employee_number = 0;
  int hour_index = 0;

  struct employee  employee[100];

  while(fgets(file_line, line_length, fptr)){
    if (first_line_flag == 0){
      hourly_rate = atof(file_line);
      first_line_flag++;
    } else if(isalpha(file_line[0])){
      strcpy(employee[employee_number].name, file_line);

    } else {
      char * token = strtok(file_line, " ");
      while( token != NULL ) {
        employee[employee_number].hours[hour_index] = atoi(token);
        employee[employee_number].total_salary += GetWeeklyPay(hourly_rate, atoi(token));
        token = strtok(NULL, " ");
        hour_index++; 
      }
      employee_number++;
      hour_index = 0;
    }  
  }
  fclose(fptr);

  fptr = fopen(out_filepath,"w");
  for( int i = 0; i < employee_number; i++){
    // DisplayEmployee(employee[i]);
    SaveEmployeeData(&fptr, employee[i]);
  }
  fclose(fptr);

  return 0;
}

double GetWeeklyPay(double hourly_rate, int hours){
  int weekly_pay = 0;
  int tmp = 0;

  if (hours<31){
    weekly_pay = hours * hourly_rate;
  }else{
    tmp = hours - 30;
    weekly_pay = 30 * hourly_rate;
    hours = tmp;
    if (hours<10){
      weekly_pay += hours * (1.5 * hourly_rate);
    }else{
      tmp = hours - 10;
      weekly_pay += 10 * (1.5 * hourly_rate) + tmp * (2 * hourly_rate);
    }
  }

  return weekly_pay;
}

void DisplayEmployee(struct employee employee){
  int total_hours = 0;
  for (int i = 0 ; i<12; i++){
    total_hours += employee.hours[i];
  }
  printf("Employee Name: %s\n", employee.name);
  printf("Total hours worked: %i\n", total_hours);
  printf("Total salary: %.2f\n", employee.total_salary);
}

