class Test:
    def __init__(self,name,roll) -> None:
        self.name=name
        self.roll=roll
    def show(self):
        print(self.name)
        print(self.roll)
    @classmethod
    def show_all(cls):
        for obj in cls:
            obj.show()
    @staticmethod
    def get_():
        return 10

obj=Test("Debnil",10)
obj.show()
Test.show_all()
print(Test.get_())
print(obj.get())


