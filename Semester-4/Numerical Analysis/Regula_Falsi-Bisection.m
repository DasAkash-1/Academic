f = @(x) x^2 - 5;
a = input('Enter lower bound a: ');
b = input('Enter upper bound b: ');
aa = a; bb = b;

if f(a) * f(b) >= 0
    fprintf('f(a) * f(b) must be negtive \n');
    return
end

%Bisection
Err = abs(a - b) / 2;
i = 1;
c = 0;
bisect_i = 0; bisect_r = 0; bisect_err = 0;

while abs(Err) >= 0.0001
    c = (a + b) / 2;
    Err = abs(a - b) / 2;
    %fprintf('Iteration %d: Midpoint = %.3f, f(c) = %.3f \n', i++, c, f(c));
    bisect_i = i++; % Added i++ here to ensure the counter increments
    
    if f(a) * f(c) < 0
        b = c;
    elseif f(a) * f(c) > 0
        a = c;
    else 
        Err = 0;
        break;
    end
end

bisect_r = c; bisect_err = Err;


%regula falsi
a = aa; 
b = bb;

Err = abs(a - b) / 2;
i = 1;
c = 0;
cc = 0;
regula_i = 0; regula_r = 0; regula_err = 0; 

while 1
    c = (a * f(b) - b * f(a)) / (f(b) - f(a));
    
    if i == 1
        %fprintf('Iteration %d: c = %.4f, f(c) = %.4f, Error = N/A \n', i++, c, f(c));
        Err = 1e9;
        regula_i = i++; % Added i++ to increment counter
    else
        Err = abs((c - cc) / c);
        %fprintf('Iteration %d: c = %.4f, f(c) = %.4f, Error = %.3f%% \n', i++, c, f(c),Err * 100);
        regula_i = i++; % Added i++ to increment counter
    end
    
    %regula = i; % Typo fixed below:
    
    if i != 1 && Err < 0.0001
        break;
    end
    cc = c;
    
    if f(a) * f(c) < 0
        b = c;
    elseif f(a) * f(c) > 0
        a = c;
    else 
        break;
    end
    
end
regula_err = Err; regula_r = c;

fprintf('\n-- Root Finding Comparison --\n');
fprintf('Function: f(x) = x^2 - 5\n');
fprintf('Initial Bounds: [%d, %d]\n' , aa , bb);
fprintf('Tolerance: %g\n', 0.0001);

fprintf('Bisection Method Results:\n');
fprintf('Root: %.4f\n', bisect_r);
fprintf('Final Error: %.5f\n', bisect_err);
fprintf('Total Iterations: %d\n', bisect_i);

fprintf('Regular Falsi Method Results:\n');
fprintf('Root: %.4f\n', regula_r);
fprintf('Final Error: %.5f\n', regula_err);
fprintf('Total Iterations: %d\n', regula_i);

if regula_i < bisect_i
    fprintf('Conclusion: Regular Falsi converged faster.\n');
elseif regula_i > bisect_i
    fprintf('Conclusion: Bisection converged faster.\n');
else
    fprintf('Conclusion: Both methods converged at the same speed.\n');
end