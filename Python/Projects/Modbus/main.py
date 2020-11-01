import modbus_tk
import modbus_tk.defines as cst
import modbus_tk.modbus_tcp as modbus_tcp
import modbus_tk.utils
import time
import sys
import datetime

SLAVE_ID = 1
STARTING_ADDRESS = 200
RANGE_PARAM = 500

def timeServer():
    now = datetime.datetime.now()
    listTime = [now.second]
    return listTime

logger = modbus_tk.utils.create_logger(name="console", record_format="%(message)s")
# CREATE server
server = modbus_tcp.TcpServer()  # DEFAULT PORT=502

if __name__=="__main__":
    try:
        logger.info("running...")
        logger.info("Enter Ctrl+C for closing ModbusServer")

        server.start()
        slave_1 = server.add_slave(SLAVE_ID)
        slave_1.add_block("a", cst.HOLDING_REGISTERS, STARTING_ADDRESS, RANGE_PARAM)
        slave_1.set_values("a", STARTING_ADDRESS, range(RANGE_PARAM))

        while True:
            timeServerList = timeServer()
            for address in range(STARTING_ADDRESS, RANGE_PARAM+1):
                slave_1.set_values("a", address, (int)(timeServerList[0]))

            time.sleep(1)
            

    except modbus_tk.modbus_tcp.TcpServer as expTcpServer:
        logger.error("%s- Code=%d" % (expTcpServer, expTcpServer.get_exception_code()))

    finally:
        logger.info("destory")
        # STOP
        server.stop()
