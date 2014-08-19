// MESSAGE VICON_3Q PACKING

#define MAVLINK_MSG_ID_VICON_3Q 223

typedef struct __mavlink_vicon_3q_t
{
 int16_t t_1; ///< thrust cmd
 int16_t r_1; ///< roll cmd
 int16_t p_1; ///< pitch cmd
 int16_t y_1; ///< yaw cmd
 int16_t pwm_1; ///< pwm cmd
 int16_t t_2; ///< thrust cmd
 int16_t r_2; ///< roll cmd
 int16_t p_2; ///< pitch cmd
 int16_t y_2; ///< yaw cmd
 int16_t pwm_2; ///< pwm cmd
 int16_t t_3; ///< thrust cmd
 int16_t r_3; ///< roll cmd
 int16_t p_3; ///< pitch cmd
 int16_t y_3; ///< yaw cmd
 int16_t pwm_3; ///< pwm cmd
 uint8_t mode_1; ///< Quad ID
 uint8_t mode_2; ///< Quad ID
 uint8_t mode_3; ///< Quad ID
} mavlink_vicon_3q_t;

#define MAVLINK_MSG_ID_VICON_3Q_LEN 33
#define MAVLINK_MSG_ID_223_LEN 33



#define MAVLINK_MESSAGE_INFO_VICON_3Q { \
	"VICON_3Q", \
	18, \
	{  { "t_1", NULL, MAVLINK_TYPE_INT16_T, 0, 0, offsetof(mavlink_vicon_3q_t, t_1) }, \
         { "r_1", NULL, MAVLINK_TYPE_INT16_T, 0, 2, offsetof(mavlink_vicon_3q_t, r_1) }, \
         { "p_1", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_vicon_3q_t, p_1) }, \
         { "y_1", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_vicon_3q_t, y_1) }, \
         { "pwm_1", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_vicon_3q_t, pwm_1) }, \
         { "t_2", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_vicon_3q_t, t_2) }, \
         { "r_2", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_vicon_3q_t, r_2) }, \
         { "p_2", NULL, MAVLINK_TYPE_INT16_T, 0, 14, offsetof(mavlink_vicon_3q_t, p_2) }, \
         { "y_2", NULL, MAVLINK_TYPE_INT16_T, 0, 16, offsetof(mavlink_vicon_3q_t, y_2) }, \
         { "pwm_2", NULL, MAVLINK_TYPE_INT16_T, 0, 18, offsetof(mavlink_vicon_3q_t, pwm_2) }, \
         { "t_3", NULL, MAVLINK_TYPE_INT16_T, 0, 20, offsetof(mavlink_vicon_3q_t, t_3) }, \
         { "r_3", NULL, MAVLINK_TYPE_INT16_T, 0, 22, offsetof(mavlink_vicon_3q_t, r_3) }, \
         { "p_3", NULL, MAVLINK_TYPE_INT16_T, 0, 24, offsetof(mavlink_vicon_3q_t, p_3) }, \
         { "y_3", NULL, MAVLINK_TYPE_INT16_T, 0, 26, offsetof(mavlink_vicon_3q_t, y_3) }, \
         { "pwm_3", NULL, MAVLINK_TYPE_INT16_T, 0, 28, offsetof(mavlink_vicon_3q_t, pwm_3) }, \
         { "mode_1", NULL, MAVLINK_TYPE_UINT8_T, 0, 30, offsetof(mavlink_vicon_3q_t, mode_1) }, \
         { "mode_2", NULL, MAVLINK_TYPE_UINT8_T, 0, 31, offsetof(mavlink_vicon_3q_t, mode_2) }, \
         { "mode_3", NULL, MAVLINK_TYPE_UINT8_T, 0, 32, offsetof(mavlink_vicon_3q_t, mode_3) }, \
         } \
}


/**
 * @brief Pack a vicon_3q message
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
 * @param mode_2 Quad ID
 * @param t_2 thrust cmd
 * @param r_2 roll cmd
 * @param p_2 pitch cmd
 * @param y_2 yaw cmd
 * @param pwm_2 pwm cmd
 * @param mode_3 Quad ID
 * @param t_3 thrust cmd
 * @param r_3 roll cmd
 * @param p_3 pitch cmd
 * @param y_3 yaw cmd
 * @param pwm_3 pwm cmd
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_3q_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1, uint8_t mode_2, int16_t t_2, int16_t r_2, int16_t p_2, int16_t y_2, int16_t pwm_2, uint8_t mode_3, int16_t t_3, int16_t r_3, int16_t p_3, int16_t y_3, int16_t pwm_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[33];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_int16_t(buf, 10, t_2);
	_mav_put_int16_t(buf, 12, r_2);
	_mav_put_int16_t(buf, 14, p_2);
	_mav_put_int16_t(buf, 16, y_2);
	_mav_put_int16_t(buf, 18, pwm_2);
	_mav_put_int16_t(buf, 20, t_3);
	_mav_put_int16_t(buf, 22, r_3);
	_mav_put_int16_t(buf, 24, p_3);
	_mav_put_int16_t(buf, 26, y_3);
	_mav_put_int16_t(buf, 28, pwm_3);
	_mav_put_uint8_t(buf, 30, mode_1);
	_mav_put_uint8_t(buf, 31, mode_2);
	_mav_put_uint8_t(buf, 32, mode_3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 33);
#else
	mavlink_vicon_3q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.t_2 = t_2;
	packet.r_2 = r_2;
	packet.p_2 = p_2;
	packet.y_2 = y_2;
	packet.pwm_2 = pwm_2;
	packet.t_3 = t_3;
	packet.r_3 = r_3;
	packet.p_3 = p_3;
	packet.y_3 = y_3;
	packet.pwm_3 = pwm_3;
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;
	packet.mode_3 = mode_3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 33);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_3Q;
	return mavlink_finalize_message(msg, system_id, component_id, 33, 77);
}

/**
 * @brief Pack a vicon_3q message on a channel
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
 * @param mode_2 Quad ID
 * @param t_2 thrust cmd
 * @param r_2 roll cmd
 * @param p_2 pitch cmd
 * @param y_2 yaw cmd
 * @param pwm_2 pwm cmd
 * @param mode_3 Quad ID
 * @param t_3 thrust cmd
 * @param r_3 roll cmd
 * @param p_3 pitch cmd
 * @param y_3 yaw cmd
 * @param pwm_3 pwm cmd
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_vicon_3q_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint8_t mode_1,int16_t t_1,int16_t r_1,int16_t p_1,int16_t y_1,int16_t pwm_1,uint8_t mode_2,int16_t t_2,int16_t r_2,int16_t p_2,int16_t y_2,int16_t pwm_2,uint8_t mode_3,int16_t t_3,int16_t r_3,int16_t p_3,int16_t y_3,int16_t pwm_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[33];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_int16_t(buf, 10, t_2);
	_mav_put_int16_t(buf, 12, r_2);
	_mav_put_int16_t(buf, 14, p_2);
	_mav_put_int16_t(buf, 16, y_2);
	_mav_put_int16_t(buf, 18, pwm_2);
	_mav_put_int16_t(buf, 20, t_3);
	_mav_put_int16_t(buf, 22, r_3);
	_mav_put_int16_t(buf, 24, p_3);
	_mav_put_int16_t(buf, 26, y_3);
	_mav_put_int16_t(buf, 28, pwm_3);
	_mav_put_uint8_t(buf, 30, mode_1);
	_mav_put_uint8_t(buf, 31, mode_2);
	_mav_put_uint8_t(buf, 32, mode_3);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 33);
#else
	mavlink_vicon_3q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.t_2 = t_2;
	packet.r_2 = r_2;
	packet.p_2 = p_2;
	packet.y_2 = y_2;
	packet.pwm_2 = pwm_2;
	packet.t_3 = t_3;
	packet.r_3 = r_3;
	packet.p_3 = p_3;
	packet.y_3 = y_3;
	packet.pwm_3 = pwm_3;
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;
	packet.mode_3 = mode_3;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 33);
#endif

	msg->msgid = MAVLINK_MSG_ID_VICON_3Q;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 33, 77);
}

/**
 * @brief Encode a vicon_3q struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param vicon_3q C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_vicon_3q_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_vicon_3q_t* vicon_3q)
{
	return mavlink_msg_vicon_3q_pack(system_id, component_id, msg, vicon_3q->mode_1, vicon_3q->t_1, vicon_3q->r_1, vicon_3q->p_1, vicon_3q->y_1, vicon_3q->pwm_1, vicon_3q->mode_2, vicon_3q->t_2, vicon_3q->r_2, vicon_3q->p_2, vicon_3q->y_2, vicon_3q->pwm_2, vicon_3q->mode_3, vicon_3q->t_3, vicon_3q->r_3, vicon_3q->p_3, vicon_3q->y_3, vicon_3q->pwm_3);
}

/**
 * @brief Send a vicon_3q message
 * @param chan MAVLink channel to send the message
 *
 * @param mode_1 Quad ID
 * @param t_1 thrust cmd
 * @param r_1 roll cmd
 * @param p_1 pitch cmd
 * @param y_1 yaw cmd
 * @param pwm_1 pwm cmd
 * @param mode_2 Quad ID
 * @param t_2 thrust cmd
 * @param r_2 roll cmd
 * @param p_2 pitch cmd
 * @param y_2 yaw cmd
 * @param pwm_2 pwm cmd
 * @param mode_3 Quad ID
 * @param t_3 thrust cmd
 * @param r_3 roll cmd
 * @param p_3 pitch cmd
 * @param y_3 yaw cmd
 * @param pwm_3 pwm cmd
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_vicon_3q_send(mavlink_channel_t chan, uint8_t mode_1, int16_t t_1, int16_t r_1, int16_t p_1, int16_t y_1, int16_t pwm_1, uint8_t mode_2, int16_t t_2, int16_t r_2, int16_t p_2, int16_t y_2, int16_t pwm_2, uint8_t mode_3, int16_t t_3, int16_t r_3, int16_t p_3, int16_t y_3, int16_t pwm_3)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[33];
	_mav_put_int16_t(buf, 0, t_1);
	_mav_put_int16_t(buf, 2, r_1);
	_mav_put_int16_t(buf, 4, p_1);
	_mav_put_int16_t(buf, 6, y_1);
	_mav_put_int16_t(buf, 8, pwm_1);
	_mav_put_int16_t(buf, 10, t_2);
	_mav_put_int16_t(buf, 12, r_2);
	_mav_put_int16_t(buf, 14, p_2);
	_mav_put_int16_t(buf, 16, y_2);
	_mav_put_int16_t(buf, 18, pwm_2);
	_mav_put_int16_t(buf, 20, t_3);
	_mav_put_int16_t(buf, 22, r_3);
	_mav_put_int16_t(buf, 24, p_3);
	_mav_put_int16_t(buf, 26, y_3);
	_mav_put_int16_t(buf, 28, pwm_3);
	_mav_put_uint8_t(buf, 30, mode_1);
	_mav_put_uint8_t(buf, 31, mode_2);
	_mav_put_uint8_t(buf, 32, mode_3);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_3Q, buf, 33, 77);
#else
	mavlink_vicon_3q_t packet;
	packet.t_1 = t_1;
	packet.r_1 = r_1;
	packet.p_1 = p_1;
	packet.y_1 = y_1;
	packet.pwm_1 = pwm_1;
	packet.t_2 = t_2;
	packet.r_2 = r_2;
	packet.p_2 = p_2;
	packet.y_2 = y_2;
	packet.pwm_2 = pwm_2;
	packet.t_3 = t_3;
	packet.r_3 = r_3;
	packet.p_3 = p_3;
	packet.y_3 = y_3;
	packet.pwm_3 = pwm_3;
	packet.mode_1 = mode_1;
	packet.mode_2 = mode_2;
	packet.mode_3 = mode_3;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_VICON_3Q, (const char *)&packet, 33, 77);
#endif
}

#endif

// MESSAGE VICON_3Q UNPACKING


/**
 * @brief Get field mode_1 from vicon_3q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_3q_get_mode_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  30);
}

/**
 * @brief Get field t_1 from vicon_3q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_t_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  0);
}

/**
 * @brief Get field r_1 from vicon_3q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_r_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  2);
}

/**
 * @brief Get field p_1 from vicon_3q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_p_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field y_1 from vicon_3q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_y_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field pwm_1 from vicon_3q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_pwm_1(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field mode_2 from vicon_3q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_3q_get_mode_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  31);
}

/**
 * @brief Get field t_2 from vicon_3q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_t_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field r_2 from vicon_3q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_r_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field p_2 from vicon_3q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_p_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  14);
}

/**
 * @brief Get field y_2 from vicon_3q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_y_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  16);
}

/**
 * @brief Get field pwm_2 from vicon_3q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_pwm_2(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  18);
}

/**
 * @brief Get field mode_3 from vicon_3q message
 *
 * @return Quad ID
 */
static inline uint8_t mavlink_msg_vicon_3q_get_mode_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  32);
}

/**
 * @brief Get field t_3 from vicon_3q message
 *
 * @return thrust cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_t_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  20);
}

/**
 * @brief Get field r_3 from vicon_3q message
 *
 * @return roll cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_r_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  22);
}

/**
 * @brief Get field p_3 from vicon_3q message
 *
 * @return pitch cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_p_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  24);
}

/**
 * @brief Get field y_3 from vicon_3q message
 *
 * @return yaw cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_y_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  26);
}

/**
 * @brief Get field pwm_3 from vicon_3q message
 *
 * @return pwm cmd
 */
static inline int16_t mavlink_msg_vicon_3q_get_pwm_3(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int16_t(msg,  28);
}

/**
 * @brief Decode a vicon_3q message into a struct
 *
 * @param msg The message to decode
 * @param vicon_3q C-struct to decode the message contents into
 */
static inline void mavlink_msg_vicon_3q_decode(const mavlink_message_t* msg, mavlink_vicon_3q_t* vicon_3q)
{
#if MAVLINK_NEED_BYTE_SWAP
	vicon_3q->t_1 = mavlink_msg_vicon_3q_get_t_1(msg);
	vicon_3q->r_1 = mavlink_msg_vicon_3q_get_r_1(msg);
	vicon_3q->p_1 = mavlink_msg_vicon_3q_get_p_1(msg);
	vicon_3q->y_1 = mavlink_msg_vicon_3q_get_y_1(msg);
	vicon_3q->pwm_1 = mavlink_msg_vicon_3q_get_pwm_1(msg);
	vicon_3q->t_2 = mavlink_msg_vicon_3q_get_t_2(msg);
	vicon_3q->r_2 = mavlink_msg_vicon_3q_get_r_2(msg);
	vicon_3q->p_2 = mavlink_msg_vicon_3q_get_p_2(msg);
	vicon_3q->y_2 = mavlink_msg_vicon_3q_get_y_2(msg);
	vicon_3q->pwm_2 = mavlink_msg_vicon_3q_get_pwm_2(msg);
	vicon_3q->t_3 = mavlink_msg_vicon_3q_get_t_3(msg);
	vicon_3q->r_3 = mavlink_msg_vicon_3q_get_r_3(msg);
	vicon_3q->p_3 = mavlink_msg_vicon_3q_get_p_3(msg);
	vicon_3q->y_3 = mavlink_msg_vicon_3q_get_y_3(msg);
	vicon_3q->pwm_3 = mavlink_msg_vicon_3q_get_pwm_3(msg);
	vicon_3q->mode_1 = mavlink_msg_vicon_3q_get_mode_1(msg);
	vicon_3q->mode_2 = mavlink_msg_vicon_3q_get_mode_2(msg);
	vicon_3q->mode_3 = mavlink_msg_vicon_3q_get_mode_3(msg);
#else
	memcpy(vicon_3q, _MAV_PAYLOAD(msg), 33);
#endif
}
