clear all
load data_v2_500
t = data.time 
y1 = data.out{1}(2,:)
y2 = data.out{2}(2,:)
y3 = data.out{3}(2,:)
y4 = data.out{4}(1,:)
figure()
plot(t,y1)
figure()
plot(t,y2)
figure()
plot(t,y3)
figure()
plot(t,y4)