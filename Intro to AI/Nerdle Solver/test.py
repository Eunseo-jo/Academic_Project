import pandas as pd
import csv
import random
import time

def repeater():
    terminals = [1,2,3,4,5,6,7,8,9,0,"+","-","*","/","="]
    results = []
    for a in terminals:
        p0 = a
        if p0 == "*":
            break
        for b in terminals:
            p1 = b
            for c in terminals:
                p2 = c
                for d in terminals:
                    p3 = d
                    for e in terminals:
                        p4 = e
                        for f in terminals:
                            p5 = f
                            for g in terminals:
                                p6 = g
                                for h in terminals:
                                    p7 = h
                                    equation = str(p0) + str(p1) + str(p2) + str(p3) + str(p4) + str(p5) + str(p6) + str(p7)
                                    try:
                                        if (equation.__contains__("--") or equation.__contains__("//") or equation.__contains__("==") or not(equation.__contains__("=")) or (p7 == "+") or (p7 == "-") or (p7 == "*") or (p7 == "/") or (p7 == "=")):
                                            continue
                                        else:
                                            if eval(equation.replace("=","==")) == True:
                                                results.append(equation)
                                    except:
                                        continue
    return results

def all_possible_equations():
    file=open('a1.txt','w')
    result = repeater()
    for items in result:
        file.writelines(items+'\n')
    file.close()
    return


def parser():
    filename = "a1.txt"
    result = open("a2.txt","w")
    file = open(filename, "r")
    txt = file.readlines()
    for items in txt:
        if items.__contains__("+=") or items.__contains__("-=") or items.__contains__("*=") or items.__contains__("=*") or items.__contains__("/=") or items.__contains__("=/") or items.__contains__("+/") or items.__contains__("-/") or items.__contains__("*/") or items.__contains__("/*") or items.__contains__("//") or items.__contains__("+*") or items.__contains__("-*") or items.__contains__("/*") or items.__contains__("*/") or items.__contains__("--") or items.__contains__("-*") or items.__contains__("-/") or items.__contains__("+*") or items.__contains__("+/"):
            continue
        else:
            if len(items.split("=")) > 2:
                continue
            else:
                result.writelines(items)
    result.close()
    return

def builder():
    file = open("a2.txt")
    txt = file.readlines()
    result = []
    for items in txt:
        if eval(items.replace("=","==")) == False:
            continue
        else:
            tmp = []
            flag = False
            reject = False
            for i in items:
                if i == "\n":
                    tmp.append(i)
                    continue
                else:
                    if flag == True and (i == "+" or i == "-" or i == "*" or i == "/"):
                        reject = True
                    if i == "=":
                        flag = True
                    tmp.append(str(i))
            tmp[-1] = int(len(set(items))-1)
            tmp.append(items[:-1])
            if len(tmp) == 10 and reject == False:
                result.append(tmp)

    with open("a3.csv", "w") as f:
        writer = csv.writer(f)
        writer.writerows(result)
    return


def solver_helper(x, lst):
    y = str(x)
    flag = True
    for i in lst:
        if y.__contains__(str(i)):
            continue
        else:
            flag = False
    return flag

def result_mapper(guess, answer):
    result = ''
    i = 0
    in_play = list(set(answer))
    while i < 8:
        if guess[i] == answer[i]:
            result = result + "2"
        elif guess[i] in in_play:
            result = result + "1"
        else:
            result = result + "0"
        i += 1
    return result


def solver(answer, max):
    df = pd.read_csv('a3.csv', names=['a','b','c','d','e','f','g','h','unique','equation'], dtype={'a':str,'b':str,'c':str,'d':str,'e':str,'f':str,'g':str,'h':str,'unique':str, 'equation':str})

    invalids = []
    in_play = []

    i = 0
    guess = "9*8-7=65"
    while (i < max):
        result = result_mapper(guess, answer)
        if result == "22222222":
            return i
        else: 
            j = 0
            while j < 8:
                if int(result[j]) == 2:
                    df = df[df[df.columns[j]] == guess[j]]
                    j += 1
                elif int(result[j]) == 1:
                    in_play.append(guess[j])
                    df = df[df[df.columns[j]] != guess[j]]
                    j += 1
                else:
                    invalids.append(guess[j])
                    j += 1
            j = 0
            while j < 8:
                if len(invalids) == 0:
                    break
                for invalid in invalids:
                    df = df[df[df.columns[j]] != invalid]
                j += 1
            new_col = str(i) + "pass"
            df[new_col] = df["equation"].apply(lambda x: solver_helper(x, in_play))
            df = df[df[new_col] == True]
            x = df.sort_values(by=['unique'], ascending=False)
            guess = x["equation"].iloc[0]
            if i == 0:
                guess = "0+12/3=4"
            invalids = list(set(invalids))
            in_play = list(set(in_play))
        i+=1
    print(answer)
    return i

def real_simulator():
    start = time.time()
    statistics = {1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0}
    file = open("answers.txt", "r")
    stats = open("real_stats.txt", "w")
    overloads = open("real_overloads.txt", "w")
    txt = file.readlines()
    for items in txt:
        attempts = solver(items, 10)
        statistics[attempts+1] = statistics[attempts+1] + 1
        if attempts > 6:
            tmp = items + ") " + str(attempts) + " attempts"
            overloads.writelines(tmp)
    end = time.time()
    stats.writelines(str(statistics))
    final_time = end-start
    print(final_time)
    #stats.writelines(final_time)
    return statistics

#print(real_simulator())

def theoretical_simulator(n):
    start = time.time()
    i=0
    statistics = {1:0,2:0,3:0,4:0,5:0,6:0,7:0,8:0,9:0,10:0,11:0,12:0,13:0,14:0,15:0,16:0,17:0,18:0,19:0,20:0}
    file = open("a3.csv", "r")
    stats = open("theoretical_stats.txt", "w")
    overloads = open("theoretical_overloads.txt", "w")
    txt = file.readlines()
    while(i < n):
        answer = txt[i].split(',')[9]
        attempts = solver(answer[:-1], 20)
        statistics[attempts+1] = statistics[attempts+1] + 1
        if attempts < 6:
            tmp = answer + ") " + str(attempts) + " attempts"
            overloads.writelines(tmp)
        i += 1
        if (i%10000 == 0):
            print(i)
    end = time.time()
    stats.writelines(str(statistics))
    final_time = end-start
    print(final_time)
    #stats.writelines(final_time)
    return statistics

#print(theoretical_simulator(141099))



def user_solver():
    df = pd.read_csv('a3.csv', names=['a','b','c','d','e','f','g','h','unique','equation'], dtype={'a':str,'b':str,'c':str,'d':str,'e':str,'f':str,'g':str,'h':str,'unique':str, 'equation':str})

    invalids = []
    in_play = []

    i = 0
    guess = "9*8-7=65"
    while (i < 6):
        print("Computer's #" + str(i+1) + " guess: " + guess)
        result = input("Please input the result: ")
        
        if result == "22222222":
            return i
        else: 
            j = 0
            while j < 8:
                if int(result[j]) == 2:
                    df = df[df[df.columns[j]] == guess[j]]
                    j += 1
                elif int(result[j]) == 1:
                    in_play.append(guess[j])
                    df = df[df[df.columns[j]] != guess[j]]
                    j += 1
                else:
                    invalids.append(guess[j])
                    j += 1
            j = 0
            while j < 8:
                if len(invalids) == 0:
                    break
                for invalid in invalids:
                    df = df[df[df.columns[j]] != invalid]
                j += 1
            new_col = str(i) + "pass"
            df[new_col] = df["equation"].apply(lambda x: solver_helper(x, in_play))
            df = df[df[new_col] == True]
            x = df.sort_values(by=['unique'], ascending=False)
            guess = x["equation"].iloc[0]
            if i == 0:
                guess = "0+12/3=4"
            invalids = list(set(invalids))
            in_play = list(set(in_play))
        i+=1
    return i

user_solver()