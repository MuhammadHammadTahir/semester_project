#include<iostream>
#include<string>
#include<iomanip>
using namespace std;
void login();				//check the login requirements
void semester_data();
void faculty_data();
void student_data();
void course_enrollment();
void spring();
void fall();
void courses_data(int a);
int check_password(string pass);
void check_student_pass(int a);
void check_faculty_pass();
void upload_attendance();
void veiw_courses();
void veiw_students_enroll_in_course();
void create_assingment_quiz();
void assingment_create_list();
void quiz_create_list();
void mark_assingment();
void mark_quiz();
void find_assingment();
void find_quiz();
void veiw_grades();
void veiw_attendance();
void veiw_challan();
struct course_enroll		//use for the course enrollment of the students this will used in calculating the fee and displaying the student data for the teacher
{
	int sem;
	string name;
	string course;
	int fee;
	int reg;
	course_enroll *nptr;
};  
struct attendance
{
	string course_name;
	int reg_s;
	string student_name;
	int date;
	string month;
	int year;
	string status;
	attendance* nptr;
};
struct course
{
	string course_name;
	int credit_hours;
	string teacher;
	string course_id;
	int fee;
	string teacher_id;
};
class assingment_quiz_class
{
public:
	string name_a;
	int reg_student_a;
	string subject_a;
	int assingment_no;
	int total_ass;
	int abs_ass;
	int  marks_assingment;
	string name_q;
	int reg_student_q;
	string subject_q;
	int quiz_no;
	int abs_quiz;
	int total_quiz;
	int marks_quiz;		//apply the absolute gradding
	void assingment_create()
	{
		cout << "\nAssingment # ";
		cin >> assingment_no;
		cout << "\nSubject : ";
		cin >> subject_a;
		cout << "\nTotal marks : ";
		cin >> total_ass;
		cout << "Absolute marks : ";
		cin >> abs_ass;
	}
	void assingment_setter_mark(string n,int reg,string sub,int total, int ass_no,int marks_obt,int mark_abs )
	{
		//working
		name_a = n;
		reg_student_a = reg;
	//	cout << reg_student_a << endl;
		subject_a = sub;
	//	cout << subject_a << endl;
		total_ass = total;
	//	cout << total_ass << endl;
		assingment_no = ass_no;
	//	cout << assingment_no << endl;
		abs_ass = mark_abs;
		marks_assingment = marks_obt;
	//	cout << "\ncheck 6\n";//check
	}
	void quiz_setter_mark(string n, int reg, string sub, int total, int ass_no, int marks_obt, int mark_abs)
	{
		name_q = n;
		reg_student_q = reg;
		subject_q = sub;
		total_quiz = total;
		quiz_no = ass_no;
		abs_quiz = mark_abs;
		marks_quiz = marks_obt;
	}
	int return_ass_no()
	{
		return assingment_no;
	}
	void quiz_create()
	{
		cout << "\nQuiz # ";
		cin >> quiz_no;
		cout << "\nSubject : ";
		cin >> subject_q;
		cout << "\nTotal marks : ";
		cin >> total_quiz;
		cout << "Absolute marks : ";
		cin >> abs_quiz;
	}
	int return_quiz_no()
	{
		return quiz_no;
	}
	int assingment_total()
	{
		return total_ass;
	}
	int quiz_total()
	{
		return total_quiz;
	}
	int assingment_abs()
	{
		return abs_ass;
	}
	int quiz_abs()
	{
		return abs_quiz;
	}
};
class student
{
protected:
	string name, city, country, birth, address, cinc;
	int reg,  marks,course_enroll;
	long long phone_number;
	string password;
public:
	void set_data()
	{
		cout << "\nEnter the Name : ";
		cin.ignore();
		getline(cin, name);
		cout << "\nEnter the Registration number : ";
		cin >> reg;
		cout << "\nEnter the Phone_number : ";
		cin >> phone_number;
		cout << "\nEnter the City : ";
		cin.ignore();
		getline(cin , city);
		cout << "\nEnter the Country : ";
		cin.ignore();
		getline(cin , country);
		cout << "\nEnter the Date of Birth : ";
		cin.ignore();
		getline(cin , birth);
		cout << "\nEnter the address : ";
		cin.ignore();
		getline(cin , address);
		cout << "\nEnter the CNIC number : ";
		cin.clear();
		cin.ignore();
		getline(cin ,cinc);
		cout << "\nEnter the password : ";
		getline(cin, password, '\n');
	}
	/*void set_course()
	{

	}*/
	string password_return_base() 
	{
		return password;
	}
};
class faculty:public student
{

};
class admin:public faculty
{
	int sem_no,i;
public :
	int course_nos;
	course* ptr;
	admin()
	{
		
		ptr = NULL;
	}
	void create_semester()
	{
		cout << "\nEnter the semester number : ";
		cin >> sem_no;
		cout << "\nHow many courses do you want to Offer : ";
		cin >> course_nos;
		ptr = new course[course_nos];
		for (i = 0; i < course_nos; i++)
		{
			cout << endl<<"\nEnter the Name of the Course : ";
			cin.ignore();
			cin >> ptr[i].course_name;
			cout << "\nEnter the ID of Course : ";
			cin >> ptr[i].course_id;
			cout << "\nEnter the Creit hours of Course : ";
			cin >> ptr[i].credit_hours;
			cout << "\nEnter the Name of the teacher of the Course : ";
			cin.ignore();
			cin >> ptr[i].teacher;
			cout<< endl ;
			cout << "\nEnter the FEE of Course : ";
			cin >> ptr[i].fee;
		}
	}
	string get_courses_name(int j)
	{
		return ptr[j].course_name;
	}
	int get_courses_hour(int j)
	{
		return ptr[j].credit_hours;
	}
	string get_courses_teacher(int j)
	{
		return ptr[j].teacher;
	}
	string get_courses_id(int j)
	{
		return ptr[j].course_id;
	}
	int get_courses_fee(int j)
	{
		return ptr[j].fee;
	}
	void faculty_data()
	{
		faculty::set_data();
	}
	void student_data()
	{
		student::set_data();
	}
	string return_pass()
	{
		return student::password;
	}
	int semester_no()
	{
		return sem_no;
	}
	string return_name()
	{
		return name;
	}
	int return_reg()
	{
		return reg;
	}
	~admin()
	{
		delete ptr;
	}
};
struct assingment
{
	assingment_quiz_class assingment_1;
	assingment* nptr;
};
struct quiz
{
	assingment_quiz_class quiz_1;
	quiz* nptr;
};
struct semester
{
	admin a1;				//this is the type of course because by creationg the semsenter the admin can create the course and create the reqired things i the same semester 
	semester* nptr;
};
char op;
string admin_password="2004";
semester* fptr_sem = NULL;
semester* fptr_faculty = NULL;
semester* fptr_student = NULL;
course_enroll* fptr_course = NULL;
semester* find;
semester* currentptr_student = NULL;
semester* currentptr_semester = NULL;
string password_check;
attendance* fptr_attendance=NULL;
assingment* fptr_assingment = NULL;
quiz* fptr_quiz = NULL;
assingment* fptr_assingment_mark = NULL;		//use this to show grades of particular student in assingment
quiz* fptr_quiz_mark = NULL;		//use this to show grades of particular student in quiz
assingment* find_ass = fptr_assingment;
quiz* find_q = fptr_quiz;   //marks entry

int main()
{							// starting of menu
	while (1)
	{
		cout << "\n\t\t~~~~~~~~~~~~~~~~~~~~~~ WELCOME TO THE STUDENT REGISTRATION PORTAL ~~~~~~~~~~~~~~~~~~~~~~~~~~~ ";
		cout << "\n\nWHO ARE YOU?\n";
		cout << "\n1. ADMIN"
			<< "\n2. FACULTY MEMBER"
			<< "\n3. STUDENT"
			<< "\n\n4. EXIT  \n"
			<< "\nOPTION : ";
		cin >> op;
		switch (op)
		{
		case '1':
			login();
			break;
		case '2':
			login();
			break;
		case '3':
			login();
			break;
		case'4':
			exit(0);
			break;
		default:
			cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!\n";
			break;
		}
	}
}
void login()
{
	int count_a = 0;
	int count_fac = 0;
	int count_stud = 0;
	char op_student, op_teacher;
	int decision;
	cin.clear();
	cin.ignore();
	while (count_a != 3 && count_fac != 3&&count_stud!=3)
	{
		cout << "\nPLEASE ENTER YOUR PASSWORD : ";
		getline(cin , password_check);
		count_a++;
		count_fac++;
		count_stud++;
		if (op == '1')
		{
			if (password_check == admin_password)
			{
				while (1)
				{
					char task;
					cout << "\nWhich operation do you want to perform ? ";
					cout << "\n1. OFFER SEMESTER";
					cout << "\n2. ENTER FACULTY MEMBER"
						<< "\n3. ENTER STUDENT DATA"
						<< "\n4.RETURN TO MAIN MENU";
					cout << "\nOPTION : ";
					cin >> task;
					switch (task)
					{
					case'1':
						semester_data();
						break;
					case'2':
						faculty_data();
						break;
					case'3':
						student_data();
						break;
					case'4':
						break;
					default:
						cout << "\n!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!";
						break;
					}
					if (task == '4')
					{
						break;
					}
				}
				break;
			}
			else
			{
				cout << "\nInvalid password\n";
			}
			if (count_a == 3)		//check how many wrong attempts ?
			{
				cout << "\nYOU ENTERED 3 TIME WRONG PASSWORD PLEASE TRY AGAIN\n";
			}
		}
		else
		{
			if (op == '2')
			{
				if (fptr_faculty == NULL)
				{
					cout << "\nTHERE IS NO FACULTY MEMBER IN THE LIST \n";
					break;
				}
				else
				{
					decision=check_password(password_check);
					if (decision == 1)
					{
						while (1)
						{
							cout << "\nWhich operation do you want to perform ? \n";
							cout << "\n1. UPLOAD ATTENDANCE\n";
							cout << "\n2. ASSINGMENT/QUIZ\n";
							cout << "\n3. VEIW ASSINGNED COURSES\n";
							cout << "\n4. VEIW STUDENT ENROLLED IN A COURSE\n";
							cout << "\n5. RETURN TO MAIN MENU\n";
							cout << "\nANSWER OF TEACHER : ";
							cin >> op_teacher;
							switch (op_teacher)
							{
							case'1':
								upload_attendance();
								//upload attendance
								break;
							case'2':
								create_assingment_quiz();
								//assingments/quizes
								break;
							case'3':
								veiw_courses();
								//assined courses
								break;
							case'4':
								veiw_students_enroll_in_course();
								//veiw students enrolled
								break;
							case'5':
								break;
							default:
								cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!!\n";
								break;
							}
							if (op_teacher == '5')
							{
								break;
							}
						}
						break;
					}
					else
					{
						cout << "\nInvalid password\n";
					}
					if (count_fac == 3)		//check how many wrong attempts ?
					{
						cout << "\nYOU ENTERED 3 TIME WRONG PASSWORD PLEASE TRY AGAIN\n";
					}
				}
			}
			else
			{
				if (fptr_student == NULL)
				{
					cout << "\nTHERE IS NO STUDENT IN THE LIST \n";
					break;
				}
				else
				{
					decision = check_password(password_check);
					if (decision == 1)
					{
						cout << "\nWhich operation do you want to perform ? \n";
						cout << "\n1. COURSE ENROLLMENT\n";
						cout << "\n2. VEIW ATTENDANCE\n";
						cout << "\n3. VEIW MARKS\n";
						cout << "\n4. PRINT CHALLAN\n";
						cout << "\n5. RETURN TO MAIN MENU\n";
						while (1)
						{
							cout << "\nOPTION FOR STUDENT : ";
							cin >> op_student;
							switch (op_student)
							{
							case'1':
								course_enrollment();	//course eenrollment
								break;
							case'2':
								veiw_attendance();
								//veiw attendance
								break;
							case'3':
								veiw_grades();
								//veiw marks
								break;
							case'4':
								veiw_challan();
								//veiw fee challan
								break;
							case'5':
								break;
							default:
								cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!!\n";
								break;
							}
							if (op_student == '5')
							{
								break;
							}
						} 
						break;
					}
					else
					{
						cout << "\nInvalid password\n";
					}
					if (count_stud == 3)		//check how many wrong attempts ?
					{
						cout << "\nYOU ENTERED 3 TIME WRONG PASSWORD PLEASE TRY AGAIN\n";
					}
				}
			}
		}
	}
}
void semester_data()
{
	semester* ptr;
	ptr = new semester;
	ptr->a1.create_semester();
	if (fptr_sem == NULL)
	{ 
		fptr_sem = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		semester *current_ptr=fptr_sem;
		while (current_ptr->nptr!=NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}
}
void faculty_data()
{
	semester* ptr_fac;
	ptr_fac = new semester;
	ptr_fac->a1.faculty_data();
	if (fptr_faculty == NULL)
	{
		fptr_faculty = ptr_fac;
		ptr_fac->nptr = NULL;
	}
	else
	{
		semester* current_ptr = fptr_faculty;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr_fac;
		ptr_fac->nptr = NULL;
	}
}
void student_data()
{
	semester* ptr_stud;
	ptr_stud = new semester;
	ptr_stud->a1.student_data();
	if (fptr_student == NULL)
	{
		fptr_student = ptr_stud;
		ptr_stud->nptr = NULL;
	}
	else
	{
		semester* current_ptr = fptr_student;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr_stud;
		ptr_stud->nptr = NULL;
	}
}
int check_password(string pass)
{
	int flag = 0;
	if (op == '2')
	{
		::find = fptr_faculty;
		while (::find != NULL)
		{
			if (::find->a1.return_pass() == pass)
			{
				flag = 1;
				break;
			}
			else
			{
				::find = ::find->nptr;
			}
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!! INVALID PASSWORD !!!!!!!!!!!!!!!!!!\n";
			return 0;
		}
		else
		{
			cout << "\n*************** CONGRATULATIONS ***************\n";
			return 1;
		}
	}
	if (op == '3')
	{
		::find = fptr_student;
		while (::find != NULL)
		{
			if (::find->a1.password_return_base() == pass)
			{
				flag = 1;
				break;
			}
			else
			{
				::find = ::find->nptr;
			}
		}
		if (flag == 0)
		{
			cout << "\n!!!!!!!!!!!!!!!!! INVALID PASSWORD !!!!!!!!!!!!!!!!!!\n";
			return 0;
		}
		else
		{
			cout << "\n*************** CONGRATULATIONS ***************\n";
			return 1;
		}
	}
}
void course_enrollment()
{
	char op_c;
	cout << "\nIN WHICH CATAGORY YOU WANT TO ENROLL ? \n";
	cout << "\n1. FALL\n";
	cout << "\n2. SPRING\n";
	while (1)
	{
		cout << "\nOPTION : ";
		cin >> op_c;
		switch (op_c)
		{
		case'1':
			fall();
			break;
		case'2':
			spring();
			break;
		default:
			cout << "\n!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!!!!!\n";
			break;
		}
		break;
	}
}
void spring()
{
	int sem_choose, ans;
	semester* ptr;
	ptr = fptr_sem;
	if (fptr_sem == NULL)
	{
		cout << "\nThere is no semester offered\n";
	}
	else
	{
		cout << setw(25) << left << "Semester No." << setw(25) << left << "Catagory\n";
		while (ptr != NULL)
		{
			if (ptr->a1.semester_no() == 2 || ptr->a1.semester_no() == 4 || ptr->a1.semester_no() == 6 || ptr->a1.semester_no() == 8)
			{
				cout << endl << setw(25) << left << ptr->a1.semester_no() << setw(25) << left << "SPRING"<<endl;
			}
			ptr = ptr->nptr; // Move the pointer to the next node in every iteration
		}
	}
	while (1)
	{
		cout << "\nIn which semester do you want to enroll ? \n";
		cin >> sem_choose;
		if (sem_choose == 2 || sem_choose == 4 || sem_choose == 6 || sem_choose == 8)
		{
			while (1)
			{
				courses_data(sem_choose);
				cout << "\nDO you want to enroll another course ?      1. (YES)        2. (NO)";
				cin >> ans;
				if (ans == 2)
				{
					break;
				}
				else
				{
					continue;
				}
			}
			if (ans == 2)
			{
				break;
			}
		}
		else
		{
			continue;
		}
	}
}
void fall()
{
	int sem_choose,ans;
	semester* ptr;
	ptr = fptr_sem;
	if (fptr_sem == NULL)
	{
		cout << "\nThere is no semester offered\n";
	}
	else
	{
		cout << setw(25) << left << "Semester No." << setw(25) << left << "Catagory\n";
		while (ptr != NULL)
		{
			if (ptr->a1.semester_no() == 1 || ptr->a1.semester_no() == 3 || ptr->a1.semester_no() == 5 || ptr->a1.semester_no() == 7)
			{
				cout << endl << setw(25) << left << ptr->a1.semester_no() << setw(25) << left << "FALL"<<endl;
			}
			ptr = ptr->nptr; // Move the pointer to the next node in every iteration
		}
	}
	while (1)
	{
		cout << "\nIn which semester do you want to enroll ? \n";
		cout << "\nOption : ";
		cin >> sem_choose;
		if (sem_choose == 1 || sem_choose == 3 || sem_choose == 5 || sem_choose == 7)
		{
			while (1)
			{
				courses_data(sem_choose);
				cout << "\nDO you want to enroll another course ?      1. (YES)        2. (NO)\n";
				cout << "OPTION : ";
				cin >> ans;
				if (ans == 2)
				{
					break;
				}
				else
				{
					continue;
				}
			}
			if (ans == 2)
			{
				break;
			}
		}
		else
		{
			continue;
		}
	}
}
void courses_data(int a)
{
	int i=0,op_course,j=0;
	course_enroll* ptr;
	ptr = new course_enroll;
	check_student_pass(a);
	ptr->sem = currentptr_semester->a1.semester_no();
	ptr->name = currentptr_student->a1.return_name();
	ptr->reg = currentptr_student->a1.return_reg();
	cout << setw(25) << left << "SR.no" << setw(25) << left << "Course ID" << setw(25) << left << "Course" << setw(25) << left << "Credit Hours" << setw(25) << left << "Teacher\n";
	while (j<currentptr_semester->a1.course_nos)
	{
		cout <<endl<< setw(25) << left << i+1 << setw(25) << left << currentptr_semester->a1.get_courses_id(i) << setw(25) << left << currentptr_semester->a1.get_courses_name(i) << setw(25) << left << currentptr_semester->a1.get_courses_hour(i) << setw(25) << left << currentptr_semester->a1.get_courses_teacher(i)<<endl;
		i++;
		j++;
	}
	cout << "\nWhich course do you want to select ? ";
	cout << "\nOption : ";
	cin >> op_course;
	cout << "\n<--------------- ENROLLED ----------------->";
	ptr->course = currentptr_semester->a1.get_courses_name(op_course - 1);
	ptr->fee = currentptr_semester->a1.get_courses_fee(op_course - 1);
	if (fptr_course == NULL)
	{
		fptr_course = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		course_enroll* current_ptr = fptr_course;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}

}
void check_student_pass(int a)
{
	currentptr_student = fptr_student;
	while (currentptr_student != NULL)
	{
		if (currentptr_student->a1.return_pass() == password_check)
		{
			break;
		}
		currentptr_student = currentptr_student->nptr;
	}
	currentptr_semester = fptr_sem;
	while (currentptr_semester != NULL)
	{
		if (currentptr_semester->a1.semester_no() == a)
		{
			break;
		}
		currentptr_semester = currentptr_semester->nptr;
	}
}
void upload_attendance()
{
	string name;
	int reg,flag=0,reg_student;
	cout << "\nEnter the registration no of student : ";
	cin >> reg;
	semester* student_find = fptr_student;
	if (fptr_student == NULL)
	{
		cout << "\nThere is no student in the list\n";
	}
	else
	{
		while (student_find != NULL)
		{
			if (student_find->a1.return_reg() == reg)
			{
				reg_student = student_find->a1.return_reg();
				name = student_find->a1.return_name();
				flag = 1;
				break;
			}
			student_find = student_find->nptr;
		}
	}
	if (flag == 1)
	{
		int op;
		while (1)
		{
			attendance* ptr;
			ptr = new attendance;
			ptr->reg_s = reg_student;
			ptr->student_name = name;
			cout << "\nEnter the name of the course : ";
			cin >> ptr->course_name;
			cout << "\nEnter the status of the student :   (p) for present        (a) for absent\n";
			cout << "\nANSWER : ";
			cin >> ptr->status;
			cout << "\nEnter the Date : ";
			cin >> ptr->date;
			cout << "\nEnter the Month : ";
			cin >> ptr->month;
			cout << "\nEnter the Year : ";
			cin >> ptr->year;
			if (fptr_attendance == NULL)
			{
				fptr_attendance = ptr;
				ptr->nptr = NULL;
			}
			else
			{
				attendance* current_ptr = fptr_attendance;
				while (current_ptr->nptr != NULL)
				{
					current_ptr = current_ptr->nptr;
				}
				current_ptr->nptr = ptr;
				ptr->nptr = NULL;
			}
			cout << "\nDo you want to marks attendance for the same student ?     1. (YES)      2.(NO)";
			cout << "\nOPTION : ";
			cin >> op;
			if (op == 1)
			{
				continue;
			}
			else
				break;
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!! Invalid registration no !!!!!!!!!!!!!!!!!!!!!!!\n";
	}
}
void veiw_courses()
{
	check_faculty_pass();
}
void check_faculty_pass()
{
	int i,j=0 ;
	string name;
	semester* ptr_check_name;			// this is for geetting the name of teacher 
	ptr_check_name = fptr_faculty;
	semester* ptr_course_no = fptr_sem;		// this will giv course nos in particular semester and its name
	if (fptr_faculty == NULL)
	{
		cout << "\n!!!!!!!!! NO DATA !!!!!!!!!!!!!!!!\n";
	}
	else
	{
		while (ptr_check_name != NULL)
		{
			if (ptr_check_name->a1.return_pass() == password_check)
			{
				name = ptr_check_name->a1.return_name();
				// it is working till here
				while (ptr_course_no != NULL)
				{
					for (i = 0; i < ptr_course_no->a1.course_nos; i++)
					{
						if (name == ptr_course_no->a1.get_courses_teacher(i))
						{
							j++;
							cout << endl << j << ". " << ptr_course_no->a1.get_courses_name(i) << endl;
						}
					}
					ptr_course_no = ptr_course_no->nptr;
				}
			}
			ptr_check_name = ptr_check_name->nptr;
		}
	}
}
void veiw_students_enroll_in_course()
{
	int i=0;
	string course_student_veiw;
	check_faculty_pass();
	cout << "\nStudents of which course do you want to see ? \n";
	cout << "\nANSWER (WRITE THE NAME OF COURSE) : ";
	cin >> course_student_veiw;
	course_enroll* ptr_find;
	ptr_find = fptr_course;
	if (fptr_course == NULL)
	{
		cout << "\nThere is no student\n";
	}
	else
	{
		cout << setw(25) << left << "SR No." << setw(25) << left << "Semester No." << setw(25) << left << "Name" <<setw(25) << left << "Course\n";
		while (ptr_find != NULL)
		{
			i++;
			if (ptr_find->course == course_student_veiw)
			{
				cout <<endl<< setw(25) << left << i << setw(25) << left <<ptr_find->sem << setw(25) << left << ptr_find->name << setw(25) << left << ptr_find->course<<endl;
			}
			ptr_find = ptr_find->nptr;
		}
	}
}
void create_assingment_quiz()
{
	char op_assing_quiz;
	while (1)
	{
		cout << "\nWhich operation do you want to perform ? \n"
			<< "\n1. Create Assingment\n"
			<< "\n2. Mark Assingment\n"
			<< "\n3. Create Quiz\n"
			<< "\n4. Mark Quiz\n"
			<<"\n5. Return\n"
			<< "\nOPTION : ";
		cin >> op_assing_quiz;
		switch (op_assing_quiz)
		{
		case'1':
			assingment_create_list();
			break;
		case'2':
			mark_assingment();
			break;
		case'3':
			quiz_create_list();
			break;
		case'4':
			mark_quiz();
			break;
		case'5':
			break;
		default:
			cout << "\n!!!!!!!!!!!!!!!!!!!! WRONG INPUT !!!!!!!!!!!!!!!";
			break;
		}
		if (op_assing_quiz == '5')
		{
			break;
		}
	}
}
void assingment_create_list()
{
	assingment* ptr;
	ptr = new assingment;
	cout << "\ncheck 1\n";
	ptr->assingment_1.assingment_create();
	if (fptr_assingment == NULL)
	{
		fptr_assingment = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		assingment* current_ptr = fptr_assingment;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}
	cout << "\ncheck 2\n";
}
void quiz_create_list()
{

	quiz* ptr;
	ptr = new quiz;
	ptr->quiz_1.quiz_create();
	if (fptr_quiz == NULL)
	{
		fptr_quiz = ptr;
		ptr->nptr = NULL;
	}
	else
	{
		quiz* current_ptr = fptr_quiz;
		while (current_ptr->nptr != NULL)
		{
			current_ptr = current_ptr->nptr;
		}
		current_ptr->nptr = ptr;
		ptr->nptr = NULL;
	}
}
void mark_assingment()
{
	int flag = 0;
	int reg_find, reg, marks_ob;
	string name;
	find_assingment();
	assingment* ptr;
	ptr = new assingment;
	semester* student_find = fptr_student;
	ptr->nptr = NULL;
	cout << "\nEnter the registration no of the student : ";
	cin >> reg_find;
	if (fptr_student == NULL)
	{
		cout << "\nThere is no student in the list\n";
	}
	else
	{
		while (student_find != NULL)
		{
			if (student_find->a1.return_reg() == reg_find)
			{
				reg = student_find->a1.return_reg();
				name = student_find->a1.return_name();
				flag = 1;
				break;
			}
			student_find = student_find->nptr;
		}
	}
	if (flag == 1)
	{
		cout << "\nEnter the marks Obtain : ";
		cin >> marks_ob;
		ptr->assingment_1.assingment_setter_mark(name, reg, find_ass->assingment_1.subject_a, find_ass->assingment_1.assingment_total(), find_ass->assingment_1.return_ass_no(), marks_ob, find_ass->assingment_1.assingment_abs());
		if (fptr_assingment_mark == NULL)
		{
			fptr_assingment_mark = ptr;
		}
		else
		{
			assingment* current_ptr = fptr_assingment_mark;
			while (current_ptr->nptr != NULL)
			{
				current_ptr = current_ptr->nptr;
			}
			current_ptr->nptr = ptr;
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!! Invalid Registration No !!!!!!!!!!!!!!!!!!!!!!!!";
		return;
	}
}
void mark_quiz()
{

	int flag = 0;
	int reg_find, reg, marks_ob;
	string name;
	find_quiz();
	quiz* ptr;
	ptr = new quiz;
	semester* student_find = fptr_student;
	ptr->nptr = NULL;
	cout << "\nEnter the registration no of the student : ";
	cin >> reg_find;
	if (fptr_student == NULL)
	{
		cout << "\nThere is no student in the list\n";
	}
	else
	{
		while (student_find != NULL)
		{
			if (student_find->a1.return_reg() == reg_find)
			{
				reg = student_find->a1.return_reg();
				name = student_find->a1.return_name();
				flag = 1;
				break;
			}
			student_find = student_find->nptr;
		}
	}
	if (flag == 1)
	{
		cout << "\nEnter the marks Obtain : ";
		cin >> marks_ob;
		ptr->quiz_1.quiz_setter_mark(name, reg, find_q->quiz_1.subject_q, find_q->quiz_1.quiz_total(), find_q->quiz_1.return_quiz_no(), marks_ob, find_q->quiz_1.quiz_abs());
		if (fptr_quiz_mark == NULL)
		{
			fptr_quiz_mark = ptr;
		}
		else
		{
			quiz* current_ptr = fptr_quiz_mark;
			while (current_ptr->nptr != NULL)
			{
				current_ptr = current_ptr->nptr;
			}
			current_ptr->nptr = ptr;
		}
	}
	else
	{
		cout << "\n!!!!!!!!!!!!!!!!!!!!! Invalid Registration No !!!!!!!!!!!!!!!!!!!!!!!!";
		return;
	}
}
void find_assingment()
{
	int ass_no;
	cout << "\nEnter the assingment# : ";
	cin >> ass_no;
	find_ass = fptr_assingment;
	if (fptr_assingment == NULL)
	{
		cout << "\nThere is no assingment in the list\n";
	}
	while (find_ass != NULL)
	{
		if (find_ass->assingment_1.return_ass_no() == ass_no)
		{
			cout << "\ncheck 3\n";//check
			break;
		}
		find_ass = find_ass->nptr;
	}
}
void find_quiz()
{
	int quiz_no;
	cout << "\nEnter the quiz# : ";
	cin >> quiz_no;
	find_q = fptr_quiz;
	if (fptr_quiz == NULL)
	{
		cout << "\nThere is no quiz in the list\n";
	}
	while (find_q != NULL)
	{
		if (find_q->quiz_1.quiz_no== quiz_no)
		{
			break;
		}
		find_q = find_q->nptr;
	}
}
void veiw_grades()
{
	int reg;
	cout << "\nEnter your registration no : ";
	cin >> reg;
	assingment* currentptr=fptr_assingment_mark;
	quiz* current_ptr_quiz = fptr_quiz_mark;
	if (fptr_assingment_mark == NULL)
	{
		cout << "\nThere is Nothing in Assingments\n";
	}
	else
	{
		cout << "\n\t<--------------------- MARKS OF ASSINGMENTS ----------------->\n";
	//   (working)
		while (currentptr != NULL)
		{
			if (currentptr->assingment_1.reg_student_a == reg)
			{
				cout << "\nAssingment# " << currentptr->assingment_1.assingment_no << "\tObtain Marks : " << currentptr->assingment_1.marks_assingment;
			}
			currentptr = currentptr->nptr;
		}
	}
	if (fptr_quiz_mark == NULL)
	{
		cout << "\nThere is Nothing in Quiz\n";
	}
	else
	{
		cout << "\n\t<--------------------- MARKS OF QUIZES ----------------->\n";
		//working
		while (current_ptr_quiz != NULL)
		{
			if (current_ptr_quiz->quiz_1.reg_student_q == reg)
			{
				cout << "\nQuiz# " << current_ptr_quiz->quiz_1.quiz_no << "\tObtain Marks : " << current_ptr_quiz->quiz_1.marks_quiz;
			}
			current_ptr_quiz = current_ptr_quiz->nptr;
		}
	}
}
void veiw_attendance()
{
	int reg;
	cout << "\nEnter your registration no : ";
	cin >> reg;
	attendance* find=fptr_attendance;
	if (fptr_attendance == NULL)
	{
		cout << "\nThere is no Data";
	}
	else
	{
		cout << setw(25) << left << "DATE" << setw(25) << left << "Registration NO" << setw(25) << left << "Name" << setw(25) << left << "Course" << setw(25) << left << "Status\n";
		while (find != NULL)
		{
			if (find->reg_s == reg)
			{
				cout << endl << setw(25) << left << find->date<<" "<<find->month<<" "<<find->year << setw(25) << left << find->reg_s << setw(25) << left << find->student_name << setw(25) << left << find->course_name << setw(25) << left << find->status;
			}
			find = find->nptr;
		}
	}


}
void veiw_challan()
{
	int total=0,transport=15000,hostel=28000,library=5000,ip_fee=1000;
	int reg,op_challan;
	cout << "\nEnter your registration no : ";
	cin >> reg;
	cout << "\nDo you want to take Transport : 1. (YES)      2. (NO)";
	cout << "\nOPTION : ";
	cin >> op_challan;
	if (op_challan == 1)
	{
		total = total + transport;
	}
	cout << "\nDo you want to take Hostel Room : 1. (YES)      2. (NO)";
	cout << "\nOPTION : ";
	cin >> op_challan;
	if (op_challan == 1)
	{
		total = total + hostel;
	}
	total = total + ip_fee + library;
	course_enroll* find = fptr_course;
	cout << "\n\n\t<<<<------------------ FEE CHALLAN ----------------------->>>>\n";
	if (fptr_course == NULL)
	{
		cout << "\nThere is no Data \n";
	}
	else
	{
		cout << setw(25) << left << "Semester" << setw(25) << left << "Course" << setw(25) << left << "FEE\n";
		while (find != NULL)
		{
			if (find->reg == reg)
			{
				cout << endl << setw(25) << left << find->sem << setw(25) << left << find->course << setw(25) << left << find->fee<<endl;
				total = total + find->fee;
			}
			find = find->nptr;
		}
		cout << endl;
		cout << "\nTransport Fee             : " << transport;
		cout << "\nHostel Fee                : " << hostel;
		cout << "\nIP_Fee                    : " << ip_fee;
		cout << "\nLibrary Fee               : " << library;
		cout << "\n\nTotal Amonut to be Paid : " << total<<endl;
		cout << "\n\n\t<<<<------------------ THANK YOU ----------------------->>>>\n";
	}
}