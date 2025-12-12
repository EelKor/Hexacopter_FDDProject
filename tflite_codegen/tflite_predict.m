function out = tflite_predict(in)
persistent net;
if isempty(net)
    net = loadTFLiteModel('model.tflite');
    % To optimize performance, set NumThreads property based on the number 
    % of threads available on the hardware board
    net.NumThreads = 1;
end
out = net.predict(in);
end