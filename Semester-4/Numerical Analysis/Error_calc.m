fprintf('-- Part A: Single Error Computation -- \n');
trueval = input('Enter the True Value: ');
appxval = input('Enter the Approxiamte Value: ');

trueError = trueval - appxval;
absolutError = abs(trueError);
relError = absolutError / abs(trueval);
perRelError = relError * 100;

fprintf('Absolute Error: %.4f \n', absolutError);
fprintf('Relative Error: %.4f \n', relError);
fprintf('Percentage Relative Error: %.2f%% \n', perRelError);

%b
fprintf('-- Part B: Iterative Error (Approximating Pi) -- \n');
PIappx = 0, j = 1;
for i = 1 : 2 : 20
    itr = 4 / i;
    if mod(j, 2) == 0
        PIappx -= itr;
    else
        PIappx += itr;
    end
    %++j
    relError = abs((pi - PIappx) / pi) * 100;
    fprintf('Iteration %d: Approx = %.4f, Error = %.2f%%\n', j++, PIappx, relError);
            
end

%{
analysis questions:
1: Rel error is useful becaus it mesauers error relative to the True val
2: in part B as more iterations wrere made more terms were added and the accuracy increased thats why error is decreasing.
3: 
%}