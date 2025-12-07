#其实，我还是不太理解这个装饰器函数为什么要三层嵌套。
# 1. 定义异常类
class PasswordError(Exception):
    pass

class LengthError(PasswordError):
    pass

class ComplexityError(PasswordError):
    pass

class HistoryError(PasswordError):
    pass

# 2. 定义带参数的装饰器
def enforce_policy(min_length=8, history_check_count=3):
    def decorator(func):
        # 提示：wrapper 必须能接收 self 和 new_password
        def wrapper(self, new_password):
            # --- 在这里编写你的验证逻辑 ---
            
            # 1. 验证长度
            if len(new_password) < min_length:
                raise LengthError(f"密码长度必须至少为 {min_length} 位。")
            # 2. 验证特殊字符 (假设特殊字符集是 "!@#$%^&*")
            if not any(char in "!@#$%^&*" for char in new_password):
                raise ComplexityError("密码必须包含至少一个特殊字符（!@#$%^&*）。")
            # 3. 验证历史记录 (通过 self.password_history 访问)
            # 注意：history_check_count 指的是最近使用的 N 个密码
            if new_password in self.password_history[-history_check_count:]:
                raise HistoryError(f"密码不能与最近 {history_check_count} 次使用的密码重复。")
            # --- 验证通过后，执行原方法 ---
            return func(self, new_password)
        return wrapper
    return decorator

# 3. 这里的类定义不用动，专注于上面的实现
class UserAccount:
    def __init__(self, username):
        self.username = username
        self.password_history = [] # 存储过去使用的密码
        self.current_password = None

    # 这里的参数要求：最小长度10位，不能与最近3次密码重复
    @enforce_policy(min_length=10, history_check_count=3)
    def set_password(self, new_password):
        self.current_password = new_password
        self.password_history.append(new_password)
        print(f"[{self.username}] 密码修改成功！")

# --- 测试代码 (运行后看看是否符合预期) ---
if __name__ == "__main__":
    user = UserAccount("Admin")
    
    # 测试用例列表
    test_cases = [
        ("short", "短密码测试"),           # 预期：LengthError
        ("longpassword", "无符号测试"),     # 预期：ComplexityError
        ("ValidPass1!", "正常修改1"),       # 预期：成功
        ("ValidPass2@", "正常修改2"),       # 预期：成功
        ("ValidPass3#", "正常修改3"),       # 预期：成功
        ("ValidPass4$", "正常修改4"),       # 预期：成功
        ("ValidPass2@", "历史重复测试"),    # 预期：HistoryError (因为它在最近3次里)
        ("ValidPass1!", "过期历史测试")     # 预期：成功 (因为它已经被挤出最近3次了)
    ]

    for pwd, desc in test_cases:
        print(f"\n--- {desc} ({pwd}) ---")
        try:
            user.set_password(pwd)
        except PasswordError as e:
            print(f"拒绝: {type(e).__name__}")
        except Exception as e:
            print(f"系统错误: {e}")