 
 
create table student_personal_info( student_id int primary key,  
    Fname varchar(20),      Lname varchar(20),      college varchar(40),      gpa float,      major varchar(20)
); 
 
create table student_location_info( student_id int,  
    foreign key(student_id) references student_personal_info(student_id),      location varchar(25) 
); 
 
create table company( company_id int primary key, 
    name varchar(20)
); 
 
create table company_location( company_id int,  
    foreign key(company_id) references company(company_id),      location varchar(25) 
); 
 
create table student_company( student_id int, foreign key(student_id) references student_personal_info(student_id),  
    company_id int,  
    foreign key(company_id) references company(company_id)
); 
 
 
create table job_location( location_id int primary key,  
    address varchar(45) 
); 
 
create table job_posting_info( post_id int primary key,  
    post_title varchar(30),      description varchar(45),      app_link varchar(250) 
); 
 
create table applied_job( student_id int,  
    foreign key(student_id) references student_personal_info(student_id),      post_id int,  
    foreign key(post_id) references job_posting_info(post_id) 
); 
 
create table employee_info( empl_id int primary key,  
    eFname varchar(20),      Lname varchar(20),      email varchar(45),      employee_title varchar(20) 
); 
 
create table business_dev( 
empl_id int,  
    foreign key(empl_id) references employee_info(empl_id),      financial_skills varchar(45) 
); 
 
create table it_specialist( empl_id int,  
    foreign key(empl_id) references employee_info(empl_id),      software_skill varchar(45) 
); 
 
create table intern( empl_id int, foreign key(empl_id) references employee_info(empl_id)); 
 
create table project( 
Pno int primary key,  
    Pname varchar(30),  
    Plocation varchar(30)
); 
 
create table works_on( 
Pno int, foreign key(Pno) references project(Pno),      empl_id int, foreign key(empl_id) references employee_info(empl_id)
); 
 
create table department_details_info( dept_id int primary key, 
    dept_name varchar(20),      no_of_empl int 
); 
 
create table department_emp( dept_id int,  
    foreign key(dept_id) references department_details_info(dept_id),      mgr_id int, foreign key(mgr_id) references employee_info(empl_id)
); 
 
create table department_company_info( dept_id int,  
    foreign key(dept_id) references department_details_info(dept_id),      company_id int,  
    foreign key(company_id) references company(company_id) 
); 
 
 
create table employee_company( empl_id int,  
    foreign key(empl_id) references employee_info(empl_id),  
    company_id int, foreign key(company_id) references company(company_id)
); 
 
 
create table apply_later( student_id int,  
    foreign key(student_id) references student_personal_info(student_id),      post_id int,  
    foreign key(post_id) references job_posting_info(post_id)
); 
 
create table job_posting_location( post_id int,  
    foreign key(post_id) references job_posting_info(post_id),  
    location_id int,  
    foreign key(location_id) references job_location(location_id) 
); 


INSERT INTO student_personal_info values ('1111222','Rachid','Bodson','Georgia State 
University','3.30','Computer Science'); 
INSERT INTO student_personal_info values ('1111333','Alain','Bodson','Georgia State 
University','3.00','Computer Science'); 
INSERT INTO student_personal_info values ('1111444','Rita','Bodson','Georgia State 
University','3.50','Nursing'); 
INSERT INTO student_personal_info values ('2222222','Rachel','Abraham','Georgia State 
University','3.50','Computer Science'); 
INSERT INTO student_personal_info values ('2222333','Efaz','Khan','Georgia State 
University','3.50','Computer Science'); 
INSERT INTO student_personal_info values ('1212122','Daryl','Johnson','Georgia Southern 
University','3.10','Business'); 
INSERT INTO student_personal_info values ('1313133','Rick','Grims','Georgia Southern 
University','3.20','Psychology'); 
INSERT INTO student_personal_info values ('1414144','Carol','Anderson','Kennesaw State 
University','3.40','Nursing'); 
INSERT INTO student_personal_info values ('1515155','Arezoo','Hosseini','Georgia State University','3.15','Biology'); 
INSERT INTO student_personal_info values ('1616166','Issak','Taiwo','Georgia Piedmont college','3.25','Applied Math'); 
INSERT INTO student_personal_info values ('2552333','Carl','Grims','Florida State 
University','2.50','Geology'); 
INSERT INTO student_personal_info values ('1414122','Alicia','Zaleya','West Point 
University','3.33','Criminal science'); 
INSERT INTO student_personal_info values ('1515133','Keyanna','Wallace','Georgia Gwinnett College','3.25','History'); 
INSERT INTO student_personal_info values ('1616144','Israel','Seka','Kennesaw State 
University','3.65','Sociology'); 
INSERT INTO student_personal_info values ('1717155','Mehrnush','Hosseini','Georgia State 
University','3.15','Biology'); 
INSERT INTO student_personal_info values ('1818166','Marjaneh','Hosseini','Georgia Piedmont college','3.25','Physics'); 
 
INSERT INTO student_location_info values ('1818166','Atlanta'); 
INSERT INTO student_location_info values ('1717155','Miami'); 
INSERT INTO student_location_info values ('1616144','Los Angeles'); 
INSERT INTO student_location_info values ('1515133','Tampa'); 
INSERT INTO student_location_info values ('1414122','Atlanta'); 
INSERT INTO student_location_info values ('2552333','Savanna'); 
INSERT INTO student_location_info values ('1616166','Orlando'); 
INSERT INTO student_location_info values ('1515155','Newark'); 
INSERT INTO student_location_info values ('1414144','New York City'); 
INSERT INTO student_location_info values ('1111222','Atlanta'); 
INSERT INTO student_location_info values ('2222222','Atlanta'); INSERT INTO student_location_info values ('2222333','Atlanta'); 
 
INSERT INTO company values ('1234','Google'); 
INSERT INTO company values ('1122','Facbook'); 
INSERT INTO company values ('1244','Home Depot'); 
INSERT INTO company values ('1342','T-Mobile'); 
INSERT INTO company values ('1111','JP Morgan'); 
INSERT INTO company values ('1254','Oscar Health'); 
INSERT INTO company values ('1994','Kohls'); 
INSERT INTO company values ('1995','CBS'); 
INSERT INTO company values ('2000','Apex'); 
INSERT INTO company values ('1846','Chanel'); 
INSERT INTO company values ('2020','Amazon'); 
 
INSERT INTO company_location values ('1234','Los Angeles'); 
INSERT INTO company_location values ('1122','Miami'); 
INSERT INTO company_location values ('1244',' Atlanta'); 
INSERT INTO company_location values ('1342','Tampa'); 
INSERT INTO company_location values ('1111','Orlando'); 
INSERT INTO company_location values ('1254','Atlanta'); 
INSERT INTO company_location values ('1994','Atlanta'); 
INSERT INTO company_location values ('1995','Atlanta'); 
INSERT INTO company_location values ('2000','Bermingham'); 
INSERT INTO company_location values ('1846','Miami'); 
INSERT INTO company_location values ('2020','Atlanta'); 
 
INSERT INTO student_company values ('1818166','1234'); 
INSERT INTO student_company values ('1717155','1122'); 
INSERT INTO student_company values ('1616144','1244'); 
INSERT INTO student_company values ('1515133','1342'); 
INSERT INTO student_company values ('1414122','1342'); 
INSERT INTO student_company values ('2552333','1342'); 
INSERT INTO student_company values ('1616166','1994'); 
INSERT INTO student_company values ('1515155','1846'); 
INSERT INTO student_company values ('1414144','2020'); 
INSERT INTO student_company values ('1111222','2000'); 
INSERT INTO student_company values ('2222222','1234'); 
INSERT INTO student_company values ('2222333','1234'); 
 
INSERT INTO job_location values ('1010','234 Flat Shoal,Atlanta,GA'); 
INSERT INTO job_location values ('2222','135 Memorial,Atlanta,GA'); 
INSERT INTO job_location values ('3333','245 Panthersville,Miami,FL'); 
INSERT INTO job_location values ('4444','555 Lion Mountain,Orlando,FL'); 
INSERT INTO job_location values ('5555','565 Columbia Drive,Bermingham,AL'); 
INSERT INTO job_location values ('6666','666 Riverdale,Atlanta,GA'); 
INSERT INTO job_location values ('7777','142 Columbus,Atlanta,GA'); 
INSERT INTO job_location values ('8888','777 Rice,Tampa,FL'); 
INSERT INTO job_location values ('9999','818 Fire Oat,Miami,FL'); 
INSERT INTO job_location values ('1011','404 River Shoal,Atlanta,GA'); 
 
INSERT INTO job_posting_info values ('12','Computer Science','analyzing big data','https://www.google.com/data'); 
INSERT INTO job_posting_info values ('33','Business Admin','handling insurance finances','https://www.JP Morgan.com/finances'); 
INSERT INTO job_posting_info values ('45','Biology','controling diseases','https://www.CDC.com/diseases'); 
INSERT INTO job_posting_info values ('60','Journalism','reporting on coronavirus','https://www.CBS.com/covid-19'); 
INSERT INTO job_posting_info values ('20','Computer Science','testing designs','https://www.facebook.com/testing'); 
 
 
INSERT INTO applied_job values ('1818166','45'); 
INSERT INTO applied_job values ('1717155','20'); 
INSERT INTO applied_job values ('1616144','45'); 
INSERT INTO applied_job values ('1515133','33'); 
INSERT INTO applied_job values ('1414122','60'); 
INSERT INTO applied_job values ('2552333','60'); 
INSERT INTO applied_job values ('1616166','45'); 
INSERT INTO applied_job values ('1515155','33'); 
INSERT INTO applied_job values ('1414144','33'); 
INSERT INTO applied_job values ('1111222','20'); 
INSERT INTO applied_job values ('2222222','12'); 
INSERT INTO applied_job values ('2222333','12'); 
 
INSERT INTO employee_info values 
('3333222','Rasheed','Hamed','rasheedhamed@gmail.com','web designer'); 
INSERT INTO employee_info values ('4444333','Atayi','Carlors','atayicarlors@yahoo.com','web programmer'); 
INSERT INTO employee_info values ('5555444','Rita','Juan','rita12@gmail.com','Nurse'); 
INSERT INTO employee_info values 
('8485838','Rochella','Koutop','koutop1234@icloud.com','Database analyzer'); 
INSERT INTO employee_info values ('2222444','Eyaz','Davids','eyazdav@gmail.com','App designer'); 
INSERT INTO employee_info values ('1313122','Rick','Johnson','rickj1@gmail.com','Business Advisor'); 
INSERT INTO employee_info values 
('1414133','Mehdi','Azar','mehdiaz@gmail.com','Psychologist'); 
INSERT INTO employee_info values 
('1515144','Carol','Peterson','carolpeterson@icloud.com','Nurse'); 
INSERT INTO employee_info values 
('1616155','Merlon','Wayan','merlon344@yahoo.com','Biologist'); 
INSERT INTO employee_info values 
('1717166','Mussa','Abdul','mussaabd14@gmail.com','Finance analyzer'); 
INSERT INTO employee_info values 
('2818333','Carl','Carlors','carls5764@gmail.com','Geologist'); 
INSERT INTO employee_info values 
('1919222','Tigist','Zaleya','tg473@icloud.com','Receptionist'); 
INSERT INTO employee_info values 
('1404133','Ruth','Wallace','ruthwallace@yahoo.com','Coder'); 
INSERT INTO employee_info values ('1505144','Judith','Seka','seka8489@icloud.com','Coding tester'); 
INSERT INTO employee_info values 
('1606155','Azaar','Hosseini','azaarhossei15@gmail.com','Game designer'); 
INSERT INTO employee_info values 
('1707166','Afia','Makou','afiamakou@icloud.com','Physicist'); 
 
INSERT INTO business_dev values ('1717166','strategistical and communication skill'); 
INSERT INTO business_dev values ('1313122','advisory and communication skill'); 
 
INSERT INTO it_specialist values ('1505144','technical coding and typing skill'); INSERT INTO it_specialist values ('1606155','video gaming skill'); 
 
INSERT INTO intern values ('3333222'); 
INSERT INTO intern values ('5555444'); 
 
INSERT INTO project values ('123','ProjectX','Los Angeles'); 
INSERT INTO project values ('112','ProjectY','Miami'); 
INSERT INTO project values ('124','Blue',' Atlanta'); 
INSERT INTO project values ('134','Lion','Tampa'); 
INSERT INTO project values ('111','T-virus','Orlando'); 
INSERT INTO project values ('125','Falcon','Atlanta'); 
INSERT INTO project values ('199','Diamond','Atlanta'); 
INSERT INTO project values ('191','LionHeart','Atlanta'); 
INSERT INTO project values ('200','ProjectZ','Bermingham'); 
INSERT INTO project values ('184','Green','Miami'); 
INSERT INTO project values ('202','InternshipFinder','Atlanta'); 
 
INSERT INTO works_on values ('123','3333222'); 
INSERT INTO works_on values ('112','5555444'); 
INSERT INTO works_on values ('124','1313122'); 
INSERT INTO works_on values ('134','1707166'); 
INSERT INTO works_on values ('111','1404133'); 
INSERT INTO works_on values ('125','2818333'); 
INSERT INTO works_on values ('199','3333222'); 
INSERT INTO works_on values ('191','1707166'); 
INSERT INTO works_on values ('200','1404133'); 
INSERT INTO works_on values ('184','5555444'); 
INSERT INTO works_on values ('202','1717166'); 
 
INSERT INTO department_details_info values ('11111','Marketing','32'); 
INSERT INTO department_details_info values ('11224','HR','25'); 
INSERT INTO department_details_info values ('23111','IT services','30'); 
INSERT INTO department_details_info values ('67211','Research development','15'); 
INSERT INTO department_details_info values ('77541','Sales','50'); 
INSERT INTO department_details_info values ('17381','Customer support','15'); 
INSERT INTO department_details_info values ('36477','Production Inventory','10'); 
 
INSERT INTO department_emp values ('11111','1616155'); 
INSERT INTO department_emp values ('11224','1606155'); 
INSERT INTO department_emp values ('23111','1505144'); 
INSERT INTO department_emp values ('67211','1707166'); 
 
INSERT INTO department_company_info values ('11111','2020'); 
INSERT INTO department_company_info values ('11224','1846'); 
INSERT INTO department_company_info values ('23111','1234'); 
INSERT INTO department_company_info values ('67211','1122'); 
INSERT INTO department_company_info values ('77541','1244'); 
INSERT INTO department_company_info values ('17381','1342'); 
INSERT INTO department_company_info values ('36477','1994'); 
 
INSERT INTO employee_company values ('3333222','1234'); 
INSERT INTO employee_company values ('4444333','1122'); 
INSERT INTO employee_company values ('5555444','1254'); 
INSERT INTO employee_company values ('8485838','2020'); 
INSERT INTO employee_company values ('2222444','1234'); 
INSERT INTO employee_company values ('1313122','2020'); 
INSERT INTO employee_company values ('1414133','1254'); 
INSERT INTO employee_company values ('1515144','1254'); 
INSERT INTO employee_company values ('1616155','1254'); 
INSERT INTO employee_company values ('1717166','1244'); 
INSERT INTO employee_company values ('1919222','1995'); 
INSERT INTO employee_company values ('1404133','1122'); 
INSERT INTO employee_company values ('1505144','1122'); 
INSERT INTO employee_company values ('1606155','1234'); 
INSERT INTO employee_company values ('1707166','1254'); 
 
INSERT INTO apply_later values ('1212122','12'); 
INSERT INTO apply_later values ('1313133','33'); 
INSERT INTO apply_later values ('1414144','45'); 
INSERT INTO apply_later values ('1515155','60'); 
INSERT INTO apply_later values ('1616166','20'); 
INSERT INTO apply_later values ('2552333','20'); 
INSERT INTO apply_later values ('1414122','60'); 
INSERT INTO apply_later values ('1515133','12'); 
INSERT INTO apply_later values ('1616144','33'); 
INSERT INTO apply_later values ('1717155','45'); 
INSERT INTO apply_later values ('1818166','12'); 
 
INSERT INTO job_posting_location values ('12','1010'); 
INSERT INTO job_posting_location values ('33','2222'); 
INSERT INTO job_posting_location values ('45','3333'); 
INSERT INTO job_posting_location values ('60','4444'); 
INSERT INTO job_posting_location values ('20','5555'); 
INSERT INTO job_posting_location values ('12','6666'); 
INSERT INTO job_posting_location values ('45','7777'); 
INSERT INTO job_posting_location values ('60','8888'); 
INSERT INTO job_posting_location values ('33','1011'); 
 

 
