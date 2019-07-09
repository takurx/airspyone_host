int rx_callback(airspy_transfer_t* transfer)
{
	uint32_t bytes_to_write;
	void* pt_rx_buffer;
	ssize_t bytes_written;
	struct timeval time_now;
	float time_difference, rate;

	if( fd != NULL ) 
	{
		switch(sample_type_val)
		{
			case AIRSPY_SAMPLE_FLOAT32_IQ:
				bytes_to_write = transfer->sample_count * FLOAT32_EL_SIZE_BYTE * 2;
				pt_rx_buffer = transfer->samples;
				break;

			case AIRSPY_SAMPLE_FLOAT32_REAL:
				bytes_to_write = transfer->sample_count * FLOAT32_EL_SIZE_BYTE * 1;
				pt_rx_buffer = transfer->samples;
				break;

			case AIRSPY_SAMPLE_INT16_IQ:
				bytes_to_write = transfer->sample_count * INT16_EL_SIZE_BYTE * 2;
				pt_rx_buffer = transfer->samples;
				break;

			case AIRSPY_SAMPLE_INT16_REAL:
				bytes_to_write = transfer->sample_count * INT16_EL_SIZE_BYTE * 1;
				pt_rx_buffer = transfer->samples;
				break;

			case AIRSPY_SAMPLE_UINT16_REAL:
				bytes_to_write = transfer->sample_count * INT16_EL_SIZE_BYTE * 1;
				pt_rx_buffer = transfer->samples;
				break;

			case AIRSPY_SAMPLE_RAW:
				if (packing_val)
				{
					bytes_to_write = transfer->sample_count * INT12_EL_SIZE_BITS / INT8_EL_SIZE_BITS;
				}
				else
				{
					bytes_to_write = transfer->sample_count * INT16_EL_SIZE_BYTE * 1;
				}
				pt_rx_buffer = transfer->samples;
				break;

			default:
				bytes_to_write = 0;
				pt_rx_buffer = NULL;
			break;
		}

		gettimeofday(&time_now, NULL);

		if (!got_first_packet)
		{
			t_start = time_now;
			time_start = time_now;
			got_first_packet = true;
		}
		else
		{
			buffer_count++;
			sample_count += transfer->sample_count;
			if (buffer_count == 50)
			{
				time_difference = TimevalDiff(&time_now, &time_start);
				rate = (float) sample_count / time_difference;
				average_rate += 0.2f * (rate - average_rate);
				global_average_rate += average_rate;
				rate_samples++;
				time_start = time_now;
				sample_count = 0;
				buffer_count = 0;
			}
		}

		if (limit_num_samples) {
			if (bytes_to_write >= bytes_to_xfer) {
				bytes_to_write = (int)bytes_to_xfer;
			}
			bytes_to_xfer -= bytes_to_write;
		}

		if(pt_rx_buffer != NULL)
		{
			bytes_written = fwrite(pt_rx_buffer, 1, bytes_to_write, fd);
		}else
		{
			bytes_written = 0;
		}
		if ( (bytes_written != bytes_to_write) || 
				 ((limit_num_samples == true) && (bytes_to_xfer == 0)) 
				)
			return -1;
		else
			return 0;
	}else
	{
		return -1;
	}
}