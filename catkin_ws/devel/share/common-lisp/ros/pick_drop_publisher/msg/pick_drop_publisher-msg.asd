
(cl:in-package :asdf)

(defsystem "pick_drop_publisher-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
)
  :components ((:file "_package")
    (:file "pick_drop" :depends-on ("_package_pick_drop"))
    (:file "_package_pick_drop" :depends-on ("_package"))
  ))