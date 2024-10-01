import os

log_directory = os.getcwd()
print("Current Directory: ", log_directory)

log_names = os.listdir(log_directory)

for log in log_names:
    if(log.endswith('.BIN') and os.path.isfile(os.path.join(log_directory, log))):
        print(log)
os.system('mavlogdump.py 호버링 (1).BIN --format csv > 호버링 (1).csv')