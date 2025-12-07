from abc import ABC, abstractmethod

class PaymentGateway(ABC):
    def __init__(self):
        pass

    @abstractmethod
    def pay(self, amount):
        ...

    @abstractmethod
    def refund(self, order_id):
        ...

class Alipay(PaymentGateway):
    def __init__(self):
        pass

    def pay(self, amount):
        print(f"支付宝支付: {amount}元")
        print('True')

    def refund(self, order_id):
        print(f"支付宝退款: 订单号 {order_id}")

class CreditCard(PaymentGateway):
    def __init__(self):
        pass

    def pay(self, amount):
        print(f"信用卡支付: {amount * 1.01}元 (含1%手续费)")
        print('True')

    def refund(self, order_id):
        print(f"信用卡退款: 订单号 {order_id}")

def main():
    try:
        p = PaymentGateway()
    except TypeError:
        pass

    byAlipay = Alipay()
    byCreditCard = CreditCard()

    byAlipay.pay(100)
    byCreditCard.pay(100)

    byAlipay.refund('900018932984')
    byCreditCard.refund('2890973901')


if __name__ == '__main__':
    main()