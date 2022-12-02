clear;
%%nastav, kde máš uložený potřebný soubory
cd \\wsl.localhost\Ubuntu\home\dd\codebl\semestralka3;
f1 = load('trset.txt'); x = f1(:,2); y = f1(:,3); z = f1(:,1); 
f2 = load('Data_ProcesUceni.txt'); a = f2(:,1);  b = f2(:,2); c = f2(:,3); w3 = f2(:,4);
xx=size(a);
yy=size(x);
xVector=(-5:0.1:5);

figure
hold on
n=0;
i=2;
j=0;

yVector=(-a(1).*xVector-c(1))/b(1);
c1=plot(xVector,yVector,'color', 'red');
text=input('Drz enter, pro ukonceni N');
    if (text=='N' | 'n')
        return
    end
while 1
    n=n+1;
    jj=j-1;
    j=j+1;
    while (w3(j)==0)
        
        j=j+1;
    end
    plot(x(n),y(n),'Marker','.','color', 'red');
    if (i>2)
        plot(x(n-1),y(n-1),'Marker','.','color', 'black');
    end
    while (i<j+1)
    delete(c1);
    yVector=(-a(i).*xVector-c(i))/b(i);
    c1=plot(xVector,yVector,'color', 'red');

    ylim([-1.1 1.1]);
    xlim([-1.1 1.1]);
    i=i+1;

% %  Vždycky čeká na enter, aby postoupil o krok dále. Enter
% %  Stačí jenom držet enter
    text=input('Drz enter, pro ukonceni N');
    if (text=='N' | 'n')
        return
    end
    end;
    
% %     Pausem lze nahradit to držení enteru. Dělá prodlevu
% %     před vykonáním dalšího příkazu. Umístnit, kam je potřeba

%      pause(0.05);
        
    if (n>=size(x))
        break;
    end;
end;