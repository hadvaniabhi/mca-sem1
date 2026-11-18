create database rdbms1;
use rdbms1;

CREATE TABLE Department (
 DeptID INT PRIMARY KEY,
 DeptName VARCHAR(50) NOT NULL UNIQUE,
 Location VARCHAR(50)
);

INSERT INTO Department (DeptID, DeptName, Location) VALUES
(10, 'Computer Science', 'Ahmedabad'),
(20, 'Data Science', 'Surat'),
(30, 'Commerce', 'Vadodara'),
(40, 'Mathematics', 'Rajkot'),
(50, 'Statistics', 'Ahmedabad');


	SELECT * FROM Department;

CREATE TABLE Employee (
 EmpID INT PRIMARY KEY,
 EmpName VARCHAR(50),
 DeptID INT,
 Salary DECIMAL(10,2),
 JoinDate DATE,
 City VARCHAR(50),
 CONSTRAINT fk_employee_department
 FOREIGN KEY (DeptID) REFERENCES Department(DeptID)
);


INSERT INTO Employee (EmpID, EmpName, DeptID, Salary, JoinDate, City) VALUES
(101, 'Aarav', 10, 45000, '2022-06-15', 'Ahmedabad'),
(102, 'Diya', 20, 52000, '2021-03-10', 'Surat'),
(103, 'Krish', 10, 38000, '2023-01-20', 'Ahmedabad'),
(104, 'Meera', 30, 60000, '2020-11-05', 'Vadodara'),
(105, 'Riya', 20, 48000, '2022-08-12', 'Surat'),
(106, 'Dev', 40, 35000, '2024-02-18', 'Rajkot'),
(107, 'Neha', 30, 55000, '2021-09-25', 'Ahmedabad'),
(108, 'Yash', 50, 42000, '2023-05-30', 'Surat'),
(109, 'Isha', 10, 65000, '2019-07-01', 'Gandhinagar'),
(110, 'Kabir', 20, 39000, '2024-01-15', 'Ahmedabad');


SELECT * FROM Employee;

CREATE TABLE Project (
    ProjectID INT PRIMARY KEY,
    ProjectName VARCHAR(100),
    DeptID INT,
    Budget DECIMAL(10,2),
    FOREIGN KEY (DeptID)
        REFERENCES Department(DeptID)
);

INSERT INTO Project VALUES
(201, 'ERP System', 10, 500000),
(202, 'Sales Analytics', 20, 350000),
(203, 'Financial Audit', 30, 250000),
(204, 'Statistical Model', 50, 300000),
(205, 'AI Research', 10, 600000),
(206, 'Data Dashboard', 20, 200000);

select * from  Project;


CREATE TABLE EmployeeProject (
    EmpID INT,
    ProjectID INT,
    HoursWorked INT,
    PRIMARY KEY (EmpID, ProjectID),
    FOREIGN KEY (EmpID)
        REFERENCES Employee(EmpID),
    FOREIGN KEY (ProjectID)
        REFERENCES Project(ProjectID)
);

INSERT INTO EmployeeProject
(EmpID, ProjectID, HoursWorked)
VALUES
(101, 201, 120),
(101, 205, 80),
(102, 202, 150),
(103, 201, 90),
(104, 203, 100),
(105, 202, 110),
(105, 206, 70),
(107, 203, 85),
(108, 204, 130),
(109, 205, 160),
(110, 206, 95);

select * from EmployeeProject;

ALTER TABLE Employee
 ADD CONSTRAINT chk_employee_salary CHECK (Salary > 0);
 
 
ALTER TABLE Employee
 MODIFY EmpName VARCHAR(50) NOT NULL;
 
 
ALTER TABLE Employee
 ADD CONSTRAINT chk_employee_city
 CHECK (City IN ('Ahmedabad', 'Surat', 'Vadodara', 'Rajkot', 'Gandhinagar'));
 
 
SHOW CREATE TABLE Employee;



ALTER TABLE Employee ADD COLUMN Email VARCHAR(100) UNIQUE;
DESCRIBE Employee;

ALTER TABLE Employee MODIFY EmpName VARCHAR(100) NOT NULL;
DESCRIBE Employee;

ALTER TABLE Employee ADD COLUMN Status VARCHAR(20) DEFAULT 'Active';
SELECT EmpID, EmpName, Status FROM Employee;

INSERT INTO Employee
(EmpID, EmpName, DeptID, Salary, JoinDate, City, Email)
VALUES
(111, 'Rahul', 10, 46000, '2025-01-10', 'Ahmedabad', 'rahul@example.com'),
(112, 'Pooja', 20, 50000, '2025-02-15', 'Surat', 'pooja@example.com');


SELECT * FROM Employee WHERE EmpID IN (111, 112);

UPDATE Employee
SET Salary = Salary * 1.10
WHERE DeptID = (SELECT DeptID FROM Department WHERE DeptName = 'Data Science');

SELECT EmpID, EmpName, Salary
FROM Employee
WHERE DeptID = (SELECT DeptID FROM Department WHERE DeptName = 'Data Science');

DELETE FROM Employee
WHERE EmpID = 106
 AND NOT EXISTS (
 SELECT 1 FROM EmployeeProject ep WHERE ep.EmpID = Employee.EmpID
 );
 
 
SELECT * FROM Employee WHERE EmpID = 106;

CREATE TABLE EmployeeHighSalary AS
SELECT * FROM Employee WHERE Salary > 45000;


SELECT * FROM EmployeeHighSalary;

CREATE TABLE TempDemo (ID INT, NoteText VARCHAR(50));

INSERT INTO TempDemo VALUES (1, 'First row'), (2, 'Second row');
SELECT * FROM TempDemo;

TRUNCATE TABLE TempDemo;

SELECT * FROM TempDemo;

RENAME TABLE TempDemo TO TempDemoRenamed;

SELECT * FROM TempDemoRenamed;

DROP TABLE TempDemoRenamed;


SELECT COUNT(*) AS TotalEmployees,
 MAX(Salary) AS MaximumSalary,
 MIN(Salary) AS MinimumSalary,
 ROUND(AVG(Salary), 2) AS AverageSalary,
 SUM(Salary) AS TotalSalary
FROM Employee;

SELECT d.DeptID, d.DeptName, COUNT(e.EmpID) AS EmployeeCount
FROM Department d LEFT JOIN Employee e ON e.DeptID = d.DeptID
GROUP BY d.DeptID, d.DeptName;

SELECT City, ROUND(AVG(Salary), 2) AS AverageSalary
FROM Employee GROUP BY City;


SELECT d.DeptName, MAX(e.Salary) AS MaximumSalary, MIN(e.Salary) AS MinimumSalary
FROM Department d JOIN Employee e ON e.DeptID = d.DeptID
GROUP BY d.DeptID, d.DeptName
HAVING MAX(e.Salary) > 50000;


SELECT UPPER(EmpName) AS EmployeeName, LOWER(City) AS City FROM Employee;

SELECT EmpName, LEFT(EmpName, 3) AS FirstThreeCharacters,
 CHAR_LENGTH(EmpName) AS NameLength
FROM Employee;

SELECT EmpName, Salary AS MonthlySalary, Salary * 12 AS AnnualSalary FROM Employee;

SELECT EmpName, CURRENT_DATE() AS CurrentDate, YEAR(JoinDate) AS JoiningYear,
 TIMESTAMPDIFF(YEAR, JoinDate, CURRENT_DATE()) AS YearsWorked
FROM Employee;

SELECT EmpName, Salary, ROUND(Salary, -3) AS RoundedSalary FROM Employee;

SELECT * FROM Employee WHERE LOWER(EmpName) LIKE '%a%';

SELECT EmpName, MONTH(JoinDate) AS JoiningMonthNumber,
 MONTHNAME(JoinDate) AS JoiningMonth
FROM Employee;

SELECT EmpName, Salary,
 CASE
 WHEN Salary >= 55000 THEN 'High'
 WHEN Salary >= 40000 THEN 'Medium'
 ELSE 'Low'
 END AS SalaryCategory
FROM Employee;

SELECT * FROM Employee WHERE Salary BETWEEN 40000 AND 60000;

SELECT * FROM Employee WHERE DeptID IN (10, 20, 50);

SELECT * FROM Employee WHERE City NOT IN ('Ahmedabad', 'Surat');

SELECT * FROM Employee ORDER BY Salary DESC, EmpName ASC;

SELECT d.DeptID, d.DeptName, COUNT(*) AS EmployeeCount
FROM Department d JOIN Employee e ON e.DeptID = d.DeptID
GROUP BY d.DeptID, d.DeptName
HAVING COUNT(*) > 2;

SELECT d.DeptName, ROUND(AVG(e.Salary), 2) AS AverageSalary
FROM Department d JOIN Employee e ON e.DeptID = d.DeptID
GROUP BY d.DeptID, d.DeptName
HAVING AVG(e.Salary) > 45000
ORDER BY AverageSalary DESC;


ALTER TABLE Employee
ADD City VARCHAR(50);

SELECT City,
       COUNT(*) AS EmployeeCount,
       SUM(emp_sal) AS TotalSalary
FROM Employee
GROUP BY City
HAVING COUNT(*) >= 2
AND SUM(emp_sal) > 80000;

show tables;

desc Employee;

SELECT *
FROM Employee
ORDER BY emp_sal DESC
LIMIT 3;

SELECT *
FROM Employee
WHERE JoinDate BETWEEN '2021-01-01' AND '2023-12-31';

SELECT d.DeptName, SUM(p.Budget) AS TotalProjectBudget
FROM Department d JOIN Project p ON p.DeptID = d.DeptID
GROUP BY d.DeptID, d.DeptName
HAVING SUM(p.Budget) > 400000;

SELECT e.emp_name, d.DeptName
FROM Employee e
INNER JOIN Department d
ON e.dept_no = d.DeptID;


	SELECT
		e.emp_no,
		e.emp_name,
		p.ProjectName
	FROM Employee e
	LEFT JOIN EmployeeProject ep
		ON e.emp_no = ep.emp_no
	LEFT JOIN Project p
		ON ep.ProjectID = p.ProjectID;
        
SELECT
    d.DeptName,
    e.emp_name
FROM Department d
LEFT JOIN Employee e
    ON e.dept_no = d.DeptID
ORDER BY d.DeptID, e.emp_no;

SELECT
    p.ProjectName,
    e.emp_name,
    ep.HoursWorked
FROM Project p
LEFT JOIN EmployeeProject ep
    ON p.ProjectID = ep.ProjectID
LEFT JOIN Employee e
    ON ep.emp_no = e.emp_no
ORDER BY p.ProjectID, e.emp_no;

SELECT
    e.emp_name,
    p.ProjectName,
    ep.HoursWorked
FROM Employee e
JOIN EmployeeProject ep
    ON e.emp_no = ep.emp_no
JOIN Project p
    ON ep.ProjectID = p.ProjectID
WHERE e.emp_no IN (
    SELECT emp_no
    FROM EmployeeProject
    GROUP BY emp_no
    HAVING COUNT(ProjectID) > 1
)
ORDER BY e.emp_no, p.ProjectID;

SELECT
    e.emp_no,
    e.emp_name,
    d.DeptName
FROM Employee e
CROSS JOIN Department d;

SELECT
    e1.emp_name AS Employee1,
    e2.emp_name AS Employee2,
    e1.dept_no AS DeptID
FROM Employee e1
JOIN Employee e2
    ON e1.dept_no = e2.dept_no
    AND e1.emp_no < e2.emp_no
ORDER BY e1.dept_no, e1.emp_no;

SELECT emp_name
FROM Employee
WHERE emp_no IN (
    SELECT emp_no
    FROM EmployeeProject
);

SELECT emp_name
FROM Employee
WHERE dept_no = 10

UNION

SELECT emp_name
FROM Employee
WHERE emp_salary > 50000;


SELECT emp_no, emp_name
FROM Employee
WHERE dept_no = 10
  AND emp_sal > 40000;
  
SELECT emp_no, emp_name, emp_sal
FROM Employee
WHERE emp_sal > (
    SELECT AVG(emp_sal)
    FROM Employee
);  

SELECT emp_no, emp_name, emp_sal
FROM Employee
WHERE emp_sal = (
    SELECT MAX(emp_sal)
    FROM Employee
);


SELECT
    e.emp_no,
    e.emp_name,
    e.emp_sal,
    e.dept_no
FROM Employee e
WHERE e.emp_sal > (
    SELECT AVG(e2.emp_sal)
    FROM Employee e2
    WHERE e2.dept_no = e.dept_no
);

SELECT
    e.emp_no,
    e.emp_name,
    e.emp_sal,
    e.dept_no
FROM Employee e
WHERE e.emp_sal = (
    SELECT MAX(e2.emp_sal)
    FROM Employee e2
    WHERE e2.dept_no = e.dept_no
);


SELECT
    e.emp_no,
    e.emp_name
FROM Employee e
WHERE EXISTS (
    SELECT 1
    FROM EmployeeProject ep
    WHERE ep.emp_no = e.emp_no
);

SELECT
    e.emp_no,
    e.emp_name
FROM Employee e
WHERE NOT EXISTS (
    SELECT 1
    FROM EmployeeProject ep
    WHERE ep.emp_no = e.emp_no
);


SELECT
    emp_no,
    emp_name,
    emp_sal,
    dept_no
FROM Employee
WHERE emp_sal > ANY (
    SELECT emp_sal
    FROM Employee
    WHERE dept_no = 10
);


SELECT
    emp_no,
    emp_name,
    emp_sal,
    dept_no
FROM Employee
WHERE emp_sal > ALL (
    SELECT emp_sal
    FROM Employee
    WHERE dept_no = 30
);


SELECT *
FROM Department
WHERE DeptID IN (
    SELECT dept_no
    FROM Employee
    WHERE emp_sal > 50000
);


SELECT DISTINCT
    e.emp_no,
    e.emp_name
FROM Employee e
JOIN EmployeeProject ep
    ON e.emp_no = ep.emp_no
JOIN Project p
    ON ep.ProjectID = p.ProjectID
WHERE p.Budget > 400000;


SELECT
    emp_no,
    emp_name,
    emp_sal,
    dept_no
FROM Employee
WHERE emp_sal > ALL (
    SELECT emp_sal
    FROM Employee
    WHERE dept_no = 40
);

SELECT
    p.ProjectID,
    p.ProjectName,
    SUM(ep.HoursWorked) AS TotalHours
FROM Project p
JOIN EmployeeProject ep
    ON p.ProjectID = ep.ProjectID
GROUP BY p.ProjectID, p.ProjectName
HAVING SUM(ep.HoursWorked) > (
    SELECT AVG(ProjectTotal)
    FROM (
        SELECT SUM(HoursWorked) AS ProjectTotal
        FROM EmployeeProject
        GROUP BY ProjectID
    ) AS ProjectHours
);


USE bank2;

DELIMITER //

CREATE PROCEDURE GetEmployeesByDept(IN dept_id INT)
BEGIN
    SELECT *
    FROM Employee
    WHERE dept_no = dept_id;
END //

DELIMITER ;


USE bank2;

DELIMITER //

CREATE PROCEDURE UpdateSalary(
    IN p_emp_id INT,
    IN p_percentage DECIMAL(5,2)
)
BEGIN
    UPDATE Employee
    SET emp_sal = emp_sal + (emp_sal * p_percentage / 100)
    WHERE emp_no = p_emp_id;

    SELECT emp_no, emp_name, emp_sal
    FROM Employee
    WHERE emp_no = p_emp_id;
END //

DELIMITER ;


USE bank2;

DELIMITER //

CREATE PROCEDURE GetDepartmentStatistics(
    IN p_dept_id INT,
    OUT p_emp_count INT,
    OUT p_avg_salary DECIMAL(10,2)
)
BEGIN
    SELECT COUNT(*), AVG(emp_sal)
    INTO p_emp_count, p_avg_salary
    FROM Employee
    WHERE dept_no = p_dept_id;
END //

DELIMITER ;

USE bank2;

DELIMITER //

CREATE FUNCTION AnnualSalary(monthly_salary DECIMAL(10,2))
RETURNS DECIMAL(12,2)
DETERMINISTIC
BEGIN
    RETURN monthly_salary * 12;
END //

DELIMITER ;

SELECT AnnualSalary(25000) AS AnnualSalary;

USE bank2;

DELIMITER //

CREATE FUNCTION GetExperienceYears(joining_date DATE)
RETURNS INT
DETERMINISTIC
BEGIN
    RETURN TIMESTAMPDIFF(YEAR, joining_date, CURDATE());
END //

DELIMITER ;


USE bank2;

DELIMITER //

CREATE PROCEDURE GetEmployeesAboveSalary(
    IN min_salary DECIMAL(10,2)
)
BEGIN
    SELECT *
    FROM Employee
    WHERE emp_sal > min_salary;
END //

DELIMITER ;

USE bank2;

DELIMITER //

CREATE PROCEDURE InsertProject(
    IN p_project_id INT,
    IN p_project_name VARCHAR(100),
    IN p_dept_id INT,
    IN p_budget DECIMAL(12,2)
)
BEGIN
    IF EXISTS (
        SELECT 1
        FROM Department
        WHERE DeptID = p_dept_id
    ) THEN
        INSERT INTO Project (ProjectID, ProjectName, DeptID, Budget)
        VALUES (p_project_id, p_project_name, p_dept_id, p_budget);
    ELSE
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Department does not exist';
    END IF;
END //

DELIMITER ;


USE bank2;

DELIMITER //

CREATE PROCEDURE DemoParameters(
    IN p_num1 INT,
    OUT p_result INT,
    INOUT p_num2 INT
)
BEGIN
    SET p_result = p_num1 * 2;
    SET p_num2 = p_num2 + p_num1;
END //

DELIMITER ;


USE bank2;

DELIMITER //

CREATE PROCEDURE GetEmployeeCursor()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_name VARCHAR(30);
    DECLARE v_salary DECIMAL(8,2);

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_name, emp_sal
        FROM Employee;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    read_loop: LOOP
        FETCH emp_cursor INTO v_name, v_salary;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SELECT v_name AS EmployeeName,
               v_salary AS Salary;
    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;



USE bank2;

DELIMITER //

CREATE PROCEDURE CalculateTotalSalary()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_salary DECIMAL(8,2);
    DECLARE total_salary DECIMAL(12,2) DEFAULT 0;

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_sal FROM Employee;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    read_loop: LOOP
        FETCH emp_cursor INTO v_salary;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SET total_salary = total_salary + v_salary;
    END LOOP;

    CLOSE emp_cursor;

    SELECT total_salary AS TotalSalary;
END //

DELIMITER ;



USE bank2;

DELIMITER //

CREATE PROCEDURE GetEmployeesBelowAverage()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_name VARCHAR(30);
    DECLARE v_salary DECIMAL(8,2);
    DECLARE v_avg_salary DECIMAL(8,2);

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_name, emp_sal
        FROM Employee;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    SELECT AVG(emp_sal)
    INTO v_avg_salary
    FROM Employee;

    OPEN emp_cursor;

    read_loop: LOOP
        FETCH emp_cursor INTO v_name, v_salary;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        IF v_salary < v_avg_salary THEN
            SELECT v_name AS EmployeeName;
        END IF;
    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;



USE bank2;

DELIMITER //

CREATE PROCEDURE ProposedSalaryIncrease()
BEGIN
    DECLARE done INT DEFAULT 0;
    DECLARE v_name VARCHAR(30);
    DECLARE v_salary DECIMAL(8,2);
    DECLARE v_new_salary DECIMAL(10,2);

    DECLARE emp_cursor CURSOR FOR
        SELECT emp_name, emp_sal
        FROM Employee
        WHERE dept_no = 20;

    DECLARE CONTINUE HANDLER FOR NOT FOUND
        SET done = 1;

    OPEN emp_cursor;

    read_loop: LOOP
        FETCH emp_cursor INTO v_name, v_salary;

        IF done = 1 THEN
            LEAVE read_loop;
        END IF;

        SET v_new_salary = v_salary * 1.05;

        SELECT v_name AS EmployeeName,
               v_salary AS CurrentSalary,
               v_new_salary AS ProposedSalary;
    END LOOP;

    CLOSE emp_cursor;
END //

DELIMITER ;

USE bank2;

DELIMITER //

CREATE TRIGGER CheckEmployeeSalary
BEFORE INSERT ON Employee
FOR EACH ROW
BEGIN
    IF NEW.emp_sal <= 0 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Salary must be greater than zero';
    END IF;
END //

DELIMITER ;


USE bank2;

DELIMITER //

CREATE TRIGGER CheckMinimumSalary
BEFORE UPDATE ON Employee
FOR EACH ROW
BEGIN
    IF NEW.emp_sal < 15000 THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Salary cannot be less than 15000';
    END IF;
END //

DELIMITER ;


USE bank2;

CREATE TABLE IF NOT EXISTS EmployeeAudit (
    AuditID INT AUTO_INCREMENT PRIMARY KEY,
    EmployeeID INT,
    Action VARCHAR(20),
    ActionTime TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);



USE bank2;

CREATE TABLE IF NOT EXISTS SalaryAudit (
    AuditID INT AUTO_INCREMENT PRIMARY KEY,
    EmployeeID INT,
    OldSalary DECIMAL(8,2),
    NewSalary DECIMAL(8,2),
    ChangeTime TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);



USE bank2;

DELIMITER //

CREATE TRIGGER PreventEmployeeDelete
BEFORE DELETE ON Employee
FOR EACH ROW
BEGIN
    IF EXISTS (
        SELECT 1
        FROM EmployeeProject
        WHERE emp_no = OLD.emp_no
    ) THEN
        SIGNAL SQLSTATE '45000'
        SET MESSAGE_TEXT = 'Cannot delete employee assigned to a project';
    END IF;
END //

DELIMITER ;



USE bank2;

CREATE TABLE IF NOT EXISTS ProjectAudit (
    AuditID INT AUTO_INCREMENT PRIMARY KEY,
    ProjectID INT,
    InsertDateTime DATETIME
);

