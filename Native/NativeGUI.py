import tkinter as tk
from tkinter import messagebox
import requests as reqs

screen = tk.Tk()

screen.title("-GUI Based Wireless Controller (ESP-12E/12..)-")
screen.geometry('648x300')

def Switch_A_ON():
    callLink(1,1)
def Switch_B_ON():
    callLink(2,1)
def Switch_A_OFF():
    callLink(1,0)
def Switch_B_OFF():
    callLink(2,0)

def success(see):
    if(see=="200"):
        messagebox.showinfo("Success","Your information has\nsended successfully") 
    else:
        messagebox.showinfo("Error","unsuccessfull\nsomething went wrong please cheak your\nIP/connection with local WLAN") 

def callLink(LEDno,LEDstatus):
    IP=getIp.get()
    NAME=getName.get()
    PASSWD=getPasswd.get()
    createURL=("http://{}/user={}&passwd={}/{}/{}").format(str(IP),str(NAME),str(PASSWD),LEDno,LEDstatus)
    data = reqs.get(createURL)
    success(str(data.status_code))

getIp=tk.Entry (screen)
getName=tk.Entry (screen)
getPasswd=tk.Entry (screen)
AON=tk.Button(screen,text="ON",command=Switch_A_ON)
BON=tk.Button(screen,text="ON",command=Switch_B_ON)
AOFF=tk.Button(screen,text="OFF",command=Switch_A_OFF)
BOFF=tk.Button(screen,text="OFF",command=Switch_B_OFF)
headding=tk.Label(screen,text="Communication Through Wireless Mode",font=("Arial Bold", 20))
switch1=tk.Label(screen,text="Switch 1",font=("Arial Bold", 15))
switch2=tk.Label(screen,text="Switch 2",font=("Arial Bold", 15))
status1=tk.Label(screen,text="Status: Off")
status2=tk.Label(screen,text="Status: Off")
ipstr=tk.Label(screen,text="Enter ip address:")
userstr=tk.Label(screen,text="Enter UserName:")
passstr=tk.Label(screen,text="Enter Password:")
headding.place(x=50,y=0)

ipstr.place(x=200,y=50)
userstr.place(x=200,y=74)
passstr.place(x=200,y=98)

getIp.place(x=300,y=50)
getName.place(x=300,y=74)
getPasswd.place(x=300,y=98)

switch1.place(x=150,y=120+26)
AON.place(x=200,y=150+26)
AOFF.place(x=230,y=150+26)
status1.place(x=270,y=160+26)

switch2.place(x=150,y=180+26)
BON.place(x=200,y=210+26)
BOFF.place(x=230,y=210+26)
status2.place(x=270,y=220+26)

screen.mainloop()
