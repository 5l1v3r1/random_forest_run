#ifndef RFR_DATA_CONTAINER_BASE_HPP
#define RFR_DATA_CONTAINER_BASE_HPP

namespace rfr{
/** \brief The interface for any data container with the minimal functionality
 *
 */
template <typename num_type = float, typename index_type = unsigned int>
class data_container_base{
  public:
    /** \brief member function for accessing a single feature value, consistency checks might be omitted for performance
     *
     * \param feature_index The index of the feature requested
     * \param sample_index The index of the data point.
     *
     * \return the stored value
     */
    virtual num_type feature (int feature_index, int sample_index) const = 0;

    /** \brief member function to query a single response value, consistency checks might be omitted for performance
     *
     * \param sample_index the response of which data point
     * \return the response value
     */
    virtual num_type response (int sample_index) const = 0;


    /** \brief method to add a single data point
     *
     * \param features an array containing all the features
     * \param num_features length of the array
     * \param response The corresponding response value
     * \return
     *
     */
    virtual bool add_data_point (num_type* feats, index_type num_elements, num_type &response) = 0;

    /** \brief query the type of a feature
     *
     * \param feature_index the index of the feature
     * \return int type of the feature: 0 - numerical value (float or int); n>0 - categorical value with n different values {1,2,...,n}
     *
     */
    virtual index_type get_type_of_feature (index_type feature_index) const = 0;

    /** \brief specifying the type of a feature
     *
     * \param feature_index the index of the feature whose type is specified
     * \param feature_type the actual type (0 - numerical, value >0 catergorical with values from {1,2,...value}
     * \return bool success of the operation (fail do to consistency checks)
     */
    virtual bool set_type_of_feature (index_type feature_index, index_type feature_type) = 0;

    virtual index_type num_features() const = 0;
    virtual index_type num_data_points()  const = 0;
};

} // namespace rfr
#endif // RFR_DATA_CONTAINER_BASE_HPP
