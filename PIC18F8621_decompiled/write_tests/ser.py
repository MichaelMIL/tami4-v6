import serial,time,sys,datetime
LOG=open('write_test_log.txt','a')
def cmd(c,wait=None):
    with serial.Serial('/dev/ttyUSB0',9600,timeout=0.3) as s:
        s.reset_input_buffer(); s.write((c+'\r').encode())
        out=b'';quiet=0;deadline=time.time()+(wait or (8 if c in('GPL','GCL','LCL','RPL','RCL') else 2.5))
        while time.time()<deadline and quiet<4:
            ch=s.read(512)
            if ch: out+=ch;quiet=0
            else: quiet+=1
    t=out.decode('latin1').replace('\r','')
    LOG.write(f'[{datetime.datetime.now():%H:%M:%S}] >>> {c}\n{t}\n'); LOG.flush()
    return [l for l in t.split('\n') if l.strip()][1:]
if __name__=='__main__':
    for c in sys.argv[1:]: print('>>>',c,'|',' / '.join(cmd(c)))
