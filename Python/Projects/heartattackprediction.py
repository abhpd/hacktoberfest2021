import numpy as np
import pandas as pd
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
import tkinter as tk


class Predictor:

    def has_disease(self, row):
        self.train(self)
        return True if self.predict(self, row) == 1 else False

    @staticmethod
    def train(self):
        df = pd.read_csv('./data/dataset.csv')
        dataset = df
        self.standardScaler = StandardScaler()
        columns_to_scale = ['age', 'sex', 'cp', 'trestbps', 'chol', 'fbs', 'restecg', 'thalach', 'exang', 'oldpeak',
                            'slope', 'ca', 'thal']
        dataset[columns_to_scale] = self.standardScaler.fit_transform(dataset[columns_to_scale])
        y = dataset['target']
        X = dataset.drop(['target'], axis=1)
        X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.33, random_state=0)
        self.knn_classifier = KNeighborsClassifier(n_neighbors=8)
        self.knn_classifier.fit(X, y)
        score = self.knn_classifier.score(X_test, y_test)
        print('--Training Complete--')
        print('Score: ' + str(score))

    @staticmethod
    def predict(self, row):
        user_df = np.array(row).reshape(1, 13)
        user_df = self.standardScaler.transform(user_df)
        predicted = self.knn_classifier.predict(user_df)
        print("Predicted: " + str(predicted[0]))
        return predicted[0]


#row = [[37, 1, 2, 130, 250, 0, 1, 187, 0, 3.5, 0, 0, 2]]
# row = [[0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0]]
# col = ['age', 'sex', 'cp', 'trestbps', 'chol', 'fbs', 'restecg', 'thalach', 'exang', 'oldpeak', 'slope', 'ca', 'thal']
# for i in range(0, 13):
#     row[0][i] = input(f"Enter {col[i]} : ")  # OverWriting the List


la=str()
def onClick():
    row=[[age.get(),gender.get(),cp.get(),tbps.get(),chol.get(),fbs.get(),restecg.get(),thalach.get(),exang.get(),oldpeak.get(),slope.get(),ca.get(),thal.get()]]
    print(row)
    predictor = Predictor()
    o = predictor.has_disease(row)
    root2 = tk.Tk()
    root2.title("Prediction Window")
    if (o == True):
        print("Person Have Heart Desease")
        la="Person Have Heart Desease"
        tk.Label(root2, text=la, font=("times new roman", 20), fg="white", bg="maroon", height=2).grid(row=15, column=1)
    else:
        print("Person Is Healthy")
        la="Person Is Healthy"
        tk.Label(root2, text=la, font=("times new roman", 20), fg="white", bg="green", height=2).grid(row=15, column=1)

    return True
root = tk.Tk()
root.title("Heart Disease Predictor")
tk.Label(root,text="""Fill your Details""",font=("times new roman", 12)).grid(row=0)
tk.Label(root,text='Age',padx=20, font=("times new roman", 12)).grid(row=1,column=0)
age = tk.IntVar()
tk.Entry(root,textvariable=age).grid(row=1,column=1)

tk.Label(root,text="""Sex""",padx=20, font=("times new roman", 12)).grid(row=2,column=0)
gender = tk.IntVar()
tk.Radiobutton(root,text="Male (1)",padx=20,variable=gender,value=1).grid(row=2,column=1)
tk.Radiobutton(root,text="Female (0)",padx=20,variable=gender,value=0).grid(row=2,column=2)

tk.Label(root,text='cp: chest pain type (0-3]', font=("times new roman", 12)).grid(row=3,column=0)
cp = tk.IntVar()
tk.Entry(root,textvariable=cp).grid(row=3,column=1)

tk.Label(root,text='trestbps: resting blood pressure', font=("times new roman", 12)).grid(row=4,column=0)
tbps = tk.IntVar()
tk.Entry(root,textvariable=tbps).grid(row=4,column=1)

tk.Label(root,text='chol: serum cholestoral in mg/dl', font=("times new roman", 12)).grid(row=5,column=0)
chol = tk.IntVar()
tk.Entry(root,textvariable=chol).grid(row=5,column=1)

tk.Label(root,text="""fbs: (fasting blood sugar > 120 mg/dl)""",padx=20, font=("times new roman", 12)).grid(row=6,column=0)
fbs=tk.IntVar()
tk.Radiobutton(root,text="True (1)",padx=20,variable=fbs,value=1).grid(row=6,column=1)
tk.Radiobutton(root,text="False (0)",padx=20,variable=fbs,value=0).grid(row=6,column=2)

tk.Label(root,text="""restecg: resting electrocardiographic results""",padx=20, font=("times new roman", 12)).grid(row=7,column=0)
restecg=tk.IntVar()
tk.Radiobutton(root,text="0",padx=20,variable=restecg,value=0).grid(row=7,column=1)
tk.Radiobutton(root,text="1",padx=20,variable=restecg,value=1).grid(row=7,column=2)
tk.Radiobutton(root,text="2",padx=20,variable=restecg,value=2).grid(row=7,column=3)

tk.Label(root,text='thalach: maximum heart rate achieved', font=("times new roman", 12)).grid(row=8,column=0)
thalach = tk.IntVar()
tk.Entry(root,textvariable=thalach).grid(row=8,column=1)

tk.Label(root,text="""exang: exercise induced angina """,padx=20, font=("times new roman", 12)).grid(row=9,column=0)
exang=tk.IntVar()
tk.Radiobutton(root,text="Yes (1)",padx=20,variable=exang,value=1).grid(row=9,column=1)
tk.Radiobutton(root,text="No (0)",padx=20,variable=exang,value=0).grid(row=9,column=2)

tk.Label(root,text='oldpeak : ST depression induced by exercise relative to rest', font=("times new roman", 12)).grid(row=10,column=0)
oldpeak = tk.DoubleVar()
tk.Entry(root,textvariable=oldpeak).grid(row=10,column=1)

tk.Label(root,text="""slope: the slope of the peak exercise ST segment""",padx=20, font=("times new roman", 12)).grid(row=11,column=0)
slope=tk.IntVar()
tk.Radiobutton(root,text="upsloping (0)",padx=20,variable=slope,value=0).grid(row=11,column=1)
tk.Radiobutton(root,text="flat (1)",padx=20,variable=slope,value=1).grid(row=11,column=2)
tk.Radiobutton(root,text="downsloping (2)",padx=20,variable=slope,value=2).grid(row=11,column=3)

tk.Label(root,text="""ca: number of major vessels (0-4) colored by flourosop""",padx=20, font=("times new roman", 12)).grid(row=12,column=0)
ca=tk.IntVar()
tk.Radiobutton(root,text="0",padx=20,variable=ca,value=0).grid(row=12,column=1)
tk.Radiobutton(root,text="1",padx=20,variable=ca,value=1).grid(row=12,column=2)
tk.Radiobutton(root,text="2",padx=20,variable=ca,value=2).grid(row=12,column=3)
tk.Radiobutton(root,text="3",padx=20,variable=ca,value=3).grid(row=12,column=4)
tk.Radiobutton(root,text="4",padx=20,variable=ca,value=4).grid(row=12,column=5)

tk.Label(root,text="""thal""",padx=20, font=("times new roman", 12)).grid(row=13,column=0)
thal=tk.IntVar()
tk.Radiobutton(root,text="0",padx=20,variable=thal,value=0).grid(row=13,column=1)
tk.Radiobutton(root,text="1",padx=20,variable=thal,value=1).grid(row=13,column=2)
tk.Radiobutton(root,text="2",padx=20,variable=thal,value=2).grid(row=13,column=3)
tk.Radiobutton(root,text="3",padx=20,variable=thal,value=3).grid(row=13,column=4)

tk.Button(root, text='Predict', command=onClick).grid(row=14, column=2, sticky=tk.W, pady=4)

root.mainloop()
