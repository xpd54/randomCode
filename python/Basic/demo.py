class Employee: 
  def determine_weekly_salary(self, weekly_hours, wage):
    salary = 40 * wage
    print("\n This Employee worked {} hrs. Paid for 40 hrs (no over time) at ${}/hr = ${}", weekly_hours, wage, salary)
    print("-----------------------------------------\n")
    
class Contractor(Employee):
  def determine_weekly_salary(self, weekly_hours, wage):
    super.determine_weekly_salary()
    salary = weekly_hours * wage
    print("\n This Contractor worked {} hrs. Paid for 40 hrs (no over time) at ${}/hr = ${}", weekly_hours, wage, salary)
  
def main(): 
  hours, wage = 50, 70
  person = Employee()
  person.determine_weekly_salary(hours, wage)
  
if __name__ == "__main__":
  main()