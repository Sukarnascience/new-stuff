from flask import Flask,render_template
import pandas as pd
from flask_restful import  Resource, Api, reqparse
import ast

app=Flask(__name__)
api=Api(app)
 
class user(Resource):
    def get(self):
        data=pd.read_csv('users.csv')
        data=data.to_dict()
        return {'data':data},200


api.add_resource(user,"/user")
#api.add_resource(location,'/location')

@app.route('/test')
def actfunc():
    return  'http://127.0.0.1:5000/user'  

@app.route('/')
def funcindex():
     return render_template('index.html')

if __name__ == "__main__" :
    app.run(debug=True)
 
