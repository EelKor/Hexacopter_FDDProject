clear; close all;
setenv("TFLITE_PATH",'D:\tensorflow')

net = loadTFLiteModel('model.tflite')
disp(net)

cfg = coder.config('lib');
cfg.TargetLang = 'C++';
codegen -config cfg tflite_predict -args ones(9,1,'single')