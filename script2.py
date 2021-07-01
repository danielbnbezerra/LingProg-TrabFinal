"""
    Universidade Federal do Rio de Janeiro - Escola Politecnica
    Departamento de Eletronica e de Computacao
    EEL670 - Linguagens de Programação - Prof. Miguel

    Trabalho de Programação - Spam Email Classifier
    Autores:  Daniel Bernardo, Letícia Tavares
         
"""
#import sys
import pandas as pd
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.naive_bayes import MultinomialNB, GaussianNB
from sklearn import svm
from sklearn.model_selection import train_test_split

def emailClassifier(user_mail_body):
    
    user_mail_body = user_mail_body.lower()
    user_mail_body = [user_mail_body]
    
    
    data = pd.read_csv('spam.csv')
    x = data['v2'].astype('str')
    y = data['v1']
     
    x_train, x_test, y_train, y_test = train_test_split(x,y,test_size=0.25)

    cv = CountVectorizer()
    features = cv.fit_transform(x_train)

    model = svm.SVC()
    model.fit(features, y_train)

    features_test = cv.transform(x_test)
    #result_acc = model.score(features_test, y_test)

    features_input = cv.transform(user_mail_body)
    pred = model.predict(features_input)
	
    print("Result: ", pred)
    return None  
#emailClassifier("(Coinbase) Amount received 2.2 Bitcoin BTC\r\n ($78,000 USD) ))Please confirm transaction: http://bit.do/Coinbase1234")
