x=500:500:2500; 
y1=[7.089 19.566 38.736 72.155 77.283]
subplot(2,2,1)
plot(x, y1);
title('Run Time');
hold on;
y2=[3.508 8.539 15.348 23.508 33.333]
subplot(2,2,1)
plot(x,y2);
y3=[2.331 5.832 10.201 15.278 20.759] 
subplot(2,2,1)
plot(x,y3);
hold off;
legend('method1','method2','method3','Location','northwest','Orientation','vertical');
xlabel('n') 
ylabel('time(s)')

y11=[80 127 165 222 224]
subplot(2,2,2)
plot(x,y11);
title('Group Count');
hold on;
y22=[52 65 86 96 113]
subplot(2,2,2)
plot(x,y22);
y33=[25 34 40 45 50]
subplot(2,2,2)
plot(x,y33);
hold off;
legend('method1','method2','method3','Location','northwest','Orientation','vertical');
xlabel('n') 
ylabel('groups')

Y=[5.133 4.351 3.466
     72.155 23.528 15.278
     12.557 68.27  7.175
     58.192 25.036  15.823];
subplot(2,2,3) 
bar(Y,'group') 
title 'Run Time' 
ylabel('time(s)')
legend('method1','method2','method3','Location','northwest','Orientation','vertical');
set(gca,'xTicklabel',{'NORMAL','CHISQUARE','POISSON','EXPONENT'});

Y1=[30 53 11
     222 96 45
     53 359  29
     161 92  43];
subplot(2,2,4) 
bar(Y1,'group') 
title 'Group Count' 
ylabel('groups')
legend('method1','method2','method3','Location','northwest','Orientation','vertical');
set(gca,'xTicklabel',{'NORMAL','CHISQUARE','POISSON','EXPONENT'});