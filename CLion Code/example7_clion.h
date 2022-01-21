//
// Created by SohamS on 20/01/2022.
//
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#ifndef GOODHOURS_H
#define GOODHOURS_H
using namespace std;

class GoodHours {
public:

    int howMany(string beforeTime, string afterTime){

        string hoursBefore = beforeTime.substr(0,2);
        string hoursAfter = afterTime.substr(0,2);
        string minutesBefore = beforeTime.substr(3,2);
        string minutesAfter = afterTime.substr(3,2);
        string currentTime = "";

        int i,j;
        int count = 0;

        if(stoi(hoursAfter + minutesAfter)<stoi(hoursBefore + minutesBefore)){
            for(i=stoi(hoursBefore);i<24;i++){
                if(i == stoi(minutesBefore)){
                    for(j=stoi(minutesBefore);j<60;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;

                        currentTime = "";
                    }
                }else{
                    for(j=0;j<60;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;

                        currentTime = "";
                    }
                }
            }
            for(i=0;i<stoi(hoursAfter)+1;i++){
                if(i == stoi(hoursAfter)){
                    for(j=0;j<stoi(minutesAfter)+1;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;

                        currentTime = "";
                    }
                }else{
                    for(j=0;j<60;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;

                        currentTime = "";
                    }
                }
            }
        }else{
            for(i=stoi(hoursBefore);i<stoi(hoursAfter)+1;i++){
                if(hoursBefore == hoursAfter){
                    for(j=stoi(minutesBefore);j<stoi(minutesAfter)+1;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;
                        currentTime = "";
                    }
                }else if(i == stoi(hoursBefore)){
                    for(j=stoi(minutesBefore);j<60;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;

                        currentTime = "";
                    }
                }else if(i == stoi(hoursAfter)){
                    for(j=0;j<stoi(minutesAfter)+1;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;

                        currentTime = "";
                    }
                }else{
                    for(j=0;j<60;j++){
                        if(i<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(i);
                        if(j<10){
                            currentTime += to_string(0);
                        }
                        currentTime += to_string(j);
                        cout<<currentTime;
                        if(((currentTime[0]-'0') == (currentTime[1]-'0')*(currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0') == (currentTime[2]-'0')*(currentTime[3]-'0')) || ((currentTime[0]-'0')*(currentTime[1]-'0')*(currentTime[2]-'0') == (currentTime[3]-'0'))){
                            cout<<" "<<currentTime;
                            count++;
                        }
                        cout<<endl;

                        currentTime = "";
                    }
                }
            }
        }

        return count;
    }
};
#endif


