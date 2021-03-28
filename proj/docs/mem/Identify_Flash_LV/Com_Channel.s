
	AREA    Com_Channel, CODE, READONLY

    EXPORT 	read_dbg_control
	EXPORT 	read_dbg_data
	EXPORT 	write_dbg_data

read_dbg_control
	MRC p14, 0, r0, c0, c0
	BX	lr

read_dbg_data
	MRC p14, 0, r0, c1, c0
	BX	lr
	
write_dbg_data
	MCR p14, 0, r0, c1, c0
	BX	lr
	
    END