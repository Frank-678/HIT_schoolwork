from abc import ABC, abstractmethod

class PaymentGateway(ABC):
    # 删除了无用的 __init__ pass

    @abstractmethod
    def pay(self, amount):
        pass

    @abstractmethod
    def refund(self, order_id):
        pass

class AliPay(PaymentGateway):  # 修正1: 类名 AliPay
    # 删除了无用的 __init__
    
    def pay(self, amount):
        print(f"支付宝支付: {amount}元")
        return True  # 修正2: 必须是 return，不能是 print

    def refund(self, order_id):
        print(f"支付宝退款: 订单号 {order_id}")

class CreditCard(PaymentGateway):
    def pay(self, amount):
        # 修正3: 计算逻辑保留，但要 return True
        print(f"信用卡支付: {amount * 1.01}元 (含1%手续费)")
        return True

    def refund(self, order_id):
        print(f"信用卡退款: 订单号 {order_id}")

# 修正4: 题目要求的“多态函数”
def process_order(gateway: PaymentGateway, money):
    if gateway.pay(money):
        print("订单处理成功")
    else:
        print("支付失败")

def main():
    # 你的实例化检查逻辑很好，保留
    try:
        p = PaymentGateway()
    except TypeError:
        print("无法实例化抽象类，测试通过")

    # 修正5: 变量名 snake_case
    ali_pay = AliPay()
    credit_card = CreditCard()

    # 使用多态函数调用，而不是直接调用
    process_order(ali_pay, 100)
    process_order(credit_card, 100)

    ali_pay.refund('900018932984')
    credit_card.refund('2890973901')

if __name__ == '__main__':
    main()