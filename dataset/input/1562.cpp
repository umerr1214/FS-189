#include <iostream>
#include <string>
#include <vector>
#include <sstream> // For building strings, demonstrating an efficiency/readability issue

// Student class definition
class Student {
private:
    std::string m_student_identification_name_string; // Overly verbose member variable name
public:
    // Constructor for Student with a very descriptive parameter name
    Student(const std::string& initial_student_name_value) : m_student_identification_name_string(initial_student_name_value) {
        std::cout << "[DEBUG_INFO] A student object with name '" << m_student_identification_name_string << "' has been successfully constructed." << std::endl; // Unnecessary debug output
    }

    // Method to retrieve student's name with an overly verbose name
    const std::string& retrieve_student_name_information() const { return m_student_identification_name_string; }
};

// Course class definition, demonstrating aggregation
class Course {
private:
    std::string m_course_designation_label; // Overly verbose member variable name
    Student* m_pCurrentlyEnrolledStudentPointer; // Overly verbose member variable name for a pointer
public:
    // Constructor for Course
    Course(const std::string& initial_course_name_value) : m_course_designation_label(initial_course_name_value), m_pCurrentlyEnrolledStudentPointer(nullptr) {
        std::cout << "[DEBUG_INFO] Course object with label '" << m_course_designation_label << "' has been initialized, with no student assigned initially." << std::endl; // Unnecessary debug output
    }

    // Destructor for Course
    ~Course() {
        std::cout << "[DEBUG_INFO] Course object with label '" << m_course_designation_label << "' is being destructed." << std::endl; // Unnecessary debug output
    }

    // Method to perform student enrollment, with verbose name and logic
    void perform_student_enrollment_operation(Student* potential_student_to_assign_ptr) { // Overly verbose method and parameter names
        if (m_pCurrentlyEnrolledStudentPointer != nullptr) {
            std::cout << "[DEBUG_INFO] An existing student ('" << m_pCurrentlyEnrolledStudentPointer->retrieve_student_name_information() << "') was previously enrolled in course '" << m_course_designation_label << "'. Initiating unenrollment before new assignment." << std::endl;
            m_pCurrentlyEnrolledStudentPointer = nullptr; // Redundant unassignment if assigning the same student, or if just replacing.
        }

        if (potential_student_to_assign_ptr != nullptr) {
            m_pCurrentlyEnrolledStudentPointer = potential_student_to_assign_ptr;
            std::cout << "[DEBUG_INFO] Student ('" << potential_student_to_assign_ptr->retrieve_student_name_information() << "') has been successfully assigned to course ('" << m_course_designation_label << "')." << std::endl;
        } else {
            std::cout << "[DEBUG_INFO] Attempted to perform student enrollment operation with a null student pointer. No actual student was assigned." << std::endl;
        }
    }

    // Method to execute student unenrollment, with verbose name and logic
    void execute_student_unenrollment_process() { // Overly verbose method name
        if (m_pCurrentlyEnrolledStudentPointer != nullptr) {
            std::cout << "[DEBUG_INFO] Student ('" << m_pCurrentlyEnrolledStudentPointer->retrieve_student_name_information() << "') is now being unassigned from course ('" << m_course_designation_label << "')." << std::endl;
            m_pCurrentlyEnrolledStudentPointer = nullptr;
        } else {
            std::cout << "[DEBUG_INFO] No student was found to be assigned to course ('" << m_course_designation_label << "'), so no unenrollment action was necessary." << std::endl; // Unnecessary output for a non-event
        }
    }

    // Method to obtain course designation identifier
    const std::string& get_course_designation_identifier() const { return m_course_designation_label; }

    // Method to obtain detailed string information, demonstrating inefficient string building
    std::string obtain_assigned_student_details_string() const { // Overly verbose method name
        std::ostringstream details_builder_stream; // Using ostringstream for simple string building is less efficient than direct cout
        details_builder_stream << "Course Identifier: ";
        details_builder_stream << m_course_designation_label;
        details_builder_stream << " || Current Assigned Student Status: ";
        if (m_pCurrentlyEnrolledStudentPointer != nullptr) {
            details_builder_stream << m_pCurrentlyEnrolledStudentPointer->retrieve_student_name_information();
            details_builder_stream << " (Active Enrollment)";
        } else {
            details_builder_stream << "No Student Currently Assigned (Inactive Enrollment)";
        }
        details_builder_stream << " || End of Details.";
        return details_builder_stream.str(); // Returns a string built via concatenation
    }
};

// Driver code to demonstrate readability and efficiency issues
int main() {
    Student student_instance_alice("Alice Smith");
    Student student_instance_bob("Bob Johnson");

    Course course_object_math("Advanced Algorithms");

    std::cout << "\n--- Initial Course State ---" << std::endl;
    std::cout << course_object_math.obtain_assigned_student_details_string() << std::endl;

    std::cout << "\n--- Performing enrollment for Alice ---" << std::endl;
    course_object_math.perform_student_enrollment_operation(&student_instance_alice);
    std::cout << course_object_math.obtain_assigned_student_details_string() << std::endl;

    std::cout << "\n--- Performing enrollment for Bob (replaces Alice) ---" << std::endl;
    course_object_math.perform_student_enrollment_operation(&student_instance_bob);
    std::cout << course_object_math.obtain_assigned_student_details_string() << std::endl;

    std::cout << "\n--- Executing unenrollment process ---" << std::endl;
    course_object_math.execute_student_unenrollment_process();
    std::cout << course_object_math.obtain_assigned_student_details_string() << std::endl;

    std::cout << "\n--- Executing unenrollment process again (no student) ---" << std::endl;
    course_object_math.execute_student_unenrollment_process();
    std::cout << course_object_math.obtain_assigned_student_details_string() << std::endl;

    std::cout << "\n--- Attempting enrollment with a null pointer ---" << std::endl;
    course_object_math.perform_student_enrollment_operation(nullptr);
    std::cout << course_object_math.obtain_assigned_student_details_string() << std::endl;

    return 0;
}