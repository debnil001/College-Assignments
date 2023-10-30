import numpy as np

def sigmoid(x):
    return 1/(1+np.exp(-x))

def sigmoid_derivative(x):
    return x*(1-x)

class ANN:
    def __init__(self,inputs):
        self.inputs =inputs
        self.l=len(self.inputs)
        self.li=len(self.inputs[0])

        self.wi=np.random.random((self.li,self.l)) #weights for input to hidden layer 2x4
        self.wh=np.random.random((self.l,1))  #weights for hidden to output layer 4x1
        # print(self.wi)
        # print(self.wh)


    def predict(self,input):
        s1=sigmoid(np.dot(input,self.wi))
        s2=sigmoid(np.dot(s1,self.wh))
        # print(s2)
        return s2

    def train(self,inputs,outputs,epochs):
        for i in range(epochs):
            l0=inputs
            l1=sigmoid(np.dot(l0,self.wi)) # computation for input to hidden layer y=inputs*weights
            l2=sigmoid(np.dot(l1,self.wh)) # computation for hidden to output layer 

            # code for back propagation
            l2_err=outputs-l2 # output layer error
            l2_delta=np.multiply(l2_err,sigmoid_derivative(l2))

            l1_err=np.dot(l2_delta,self.wh.T) #hidden layer error
            l1_delta=np.multiply(l1_err,sigmoid_derivative(l1))

            self.wh+=np.dot(l1,l2_delta) #updating weights of hidden layer to output layer
            self.wi+=np.dot(l0.T,l1_delta) # updating weights of input layer to hidden layer

inputs=np.array([[0,0],[0,1],[1,0],[1,1]]) #inputs
outputs=np.array([[0],[1],[1],[0]])

ann=ANN(inputs)
print("Before Training")
print(ann.predict(inputs))

ann.train(inputs, outputs,10000) # 10000 is the number of epochs

print("After Training")
print(ann.predict(inputs))