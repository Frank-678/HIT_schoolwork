# https://www.bilibili.com/video/BV1ZW4y127Vp/?spm_id_from=333.337.search-card.all.click&vd_source=747b6f06297e4e19f2c5c148c5c50689  时间03:57

class Employee:
    def __init__(self, name, id):
        self.name = name
        self.id = id

    def print_info(self):
        print(self.name, self.id)
    
class Fulltime(Employee):
    def __init__(fulltime_self, id, name, monthly_salary):  #子类的参数要包含id，name
        super(Fulltime, fulltime_self).__init__(name, id)
        fulltime_self.monthly_salary = monthly_salary

    def calculate_monthly_pay(self):
        return self.monthly_salary

class Parttime(Employee):
    def __init__(parttime_self, id, name, daily_salary, work_days):
        Employee.__init__(parttime_self, name, id)  #相当于用类中的函数使用了
        parttime_self.daily_salary = daily_salary
        parttime_self.work_days = work_days

    def calculate_monthly_pay(self):
        return self.daily_salary * self.work_days