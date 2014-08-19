// MESSAGE VICON_1Q PACKING

#define MAVLINK_MSG_ID_VICON_1Q 221

typedef struct __mavlink_vicon_1q_t
{
 int16_t t_1; ///< thrust cmd
 int16_t r_1; ///< roll cmd
 int16_t p_1; ///< pitch cmd
 int16_t y_1; ///< yaw cmd
 int16_t pwm_1; ///< pwm cmd
 uint8_t mode_1; ///< Quad ID
} mavlink_vicon_1q_t;

#define MAVLINK_MSG_ID_VICON_1Q_LEN 11
#define MAVLINK_MSG_ID_221_LEN 11



#define MAVLINK_MESSAGE_INFO_VICON_1Q { \
	"VICON_1Q", \
	6, \
	{  { "t_1", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_vicon_1q_t, t_1) }, \
         { "r_1", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_vicon_1q_t, r_1) }, \
         { "p_1", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vicon_1q_t, p_1) }, \
         { "y_1", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vicon_1q_t, y_1) }, \
         { "pwm_1", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vicon_1q_t, pwm_1) }, \
         { "mode_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_vicon_1q_t, mode_1) }, \
         } \
}


/**
 * @brief Pack a vicon_1q message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param mode_1 Quad ID
 * @param t_1 thrust cmd
 * @param r_1 roll cmd
 * @param p_1 pitch cmd
 * @param y_1 yaw cmd
 * @param pwm_1 pwm cmd
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_1q_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[11];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_uint8_t(buf, 10, mode_1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 11);
#else
	mavlink_vicon_1q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.mode_1 = mode_1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 11);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_1Q;
	return mavlink_finalize_message(msg, system_id, component_id, 11, 44);
}

/**
 * @brief Pack a vicon_1q message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param mode_1 Quad ID
 * @param t_1 thrust cmd
 * @param r_1 roll cmd
 * @param p_1 pitch cmd
 * @param y_1 yaw cmd
 * @param pwm_1 pwm cmd
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_1q_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode_1,int16_t t_1,int16_t r_1,int16_t p_1,int16_t y_1,int16_t pwm_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[11];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_uint8_t(buf, 10, mode_1);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 11);
#else
	mavlink_vicon_1q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.mode_1 = mode_1;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 11);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_1Q;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 11, 44);
}

/**
 * @brief Encode a vicon_1q struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vicon_1q C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vicon_1q_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vicon_1q_t* vicon_1q)
{
	return mavlink_msg_vicon_1q_pack(system_id, component_id, msg, vicon_1q->mode_1, vicon_1q->t_1, vicon_1q->r_1, vicon_1q->p_1, vicon_1q->y_1, vicon_1q->pwm_1);
}

/**
 * @brief Send a vicon_1q message
 * @param chan MAVLink channel to send the message
 *
 * @param mode_1 Quad ID
 * @param t_1 thrust cmd
 * @param r_1 roll cmd
 * @param p_1 pitch cmd
 * @param y_1 yaw cmd
 * @param pwm_1 pwm cmd
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vicon_1q_send(mavlink_channel_t chan, uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[11];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_uint8_t(buf, 10, mode_1);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_1Q, buf, 11, 44);
#else
	mavlink_vicon_1q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.mode_1 = mode_1;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_1Q, (const char *)&packet, 11, 44);
#endif
}

#endif

// MESSAGE VICON_1Q UNPACKING


/**
 * @brief Get field mode_1 from vicon_1q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_1q_get_mode_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field t_1 from vicon_1q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_1q_get_t_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field r_1 from vicon_1q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_1q_get_r_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field p_1 from vicon_1q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_1q_get_p_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field y_1 from vicon_1q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_1q_get_y_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field pwm_1 from vicon_1q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_1q_get_pwm_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Decode a vicon_1q message into a struct
 *
 * @param msg The message to decode
 * @param vicon_1q C-struct to decode the message contents into
 */
static inline void mavlink_msg_vicon_1q_decode(const mavlink_message_t* msg, mavlink_vicon_1q_t* vicon_1q)
{
#if MAVLINK_NEED_BYTE_SWAP
	vicon_1q->t_1 = mavlink_msg_vicon_1q_get_t_1(msg);
	vicon_1q->r_1 = mavlink_msg_vicon_1q_get_r_1(msg);
	vicon_1q->p_1 = mavlink_msg_vicon_1q_get_p_1(msg);
	vicon_1q->y_1 = mavlink_msg_vicon_1q_get_y_1(msg);
	vicon_1q->pwm_1 = mavlink_msg_vicon_1q_get_pwm_1(msg);
	vicon_1q->mode_1 = mavlink_msg_vicon_1q_get_mode_1(msg);
#else
	memcpy(vicon_1q, _MAV_PAYLOAD(msg), 11);
#endif
}
