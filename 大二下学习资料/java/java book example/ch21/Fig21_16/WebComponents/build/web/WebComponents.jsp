<?xml version="1.0" encoding="UTF-8"?>

<!-- Fig.26.16: WebComponents.jsp -->
<!-- Registration form that demonstrates JSF components -->
<jsp:root version="2.1" xmlns:f="http://java.sun.com/jsf/core" 
   xmlns:h="http://java.sun.com/jsf/html" 
   xmlns:jsp="http://java.sun.com/JSP/Page" 
   xmlns:webuijsf="http://www.sun.com/webui/webuijsf">
   <jsp:directive.page contentType="text/html;charset=UTF-8" 
      pageEncoding="UTF-8"/>
   <f:view>
      <webuijsf:page id="page1">
         <webuijsf:html id="html1">
            <webuijsf:head id="head1">
               <webuijsf:link id="link1" url="/resources/stylesheet.css"/>
            </webuijsf:head>
            <webuijsf:body id="body1" style="-rave-layout: grid">
               <webuijsf:form id="form1">
                  <webuijsf:staticText id="headerText" 
                     style="font-size: 18px; left: 24px; top: 24px; 
                        position: absolute" 
                     text="This is a sample registration form"/>
                  <webuijsf:staticText id="instructionText" 
                     style="font-style: italic; left: 24px; top: 48px;
                        position: absolute" 
                     text="Please fill in all fields and click Register"/>
                  <webuijsf:image id="userImage" style="left: 24px; 
                     top: 72px; position: absolute" 
                     url="/resources/user.png"/>
                  <h:panelGrid columns="4" id="gridPanel" 
                     style="height: 96px; left: 24px; top: 96px; 
                        position: absolute" width="456">
                     <webuijsf:image id="firstNameImage" 
                        url="/resources/fname.png"/>
                     <webuijsf:textField id="firstNameTextField"/>
                     <webuijsf:image id="lastNameImage" 
                        url="/resources/lname.png"/>
                     <webuijsf:textField id="lastNameTextField"/>
                     <webuijsf:image id="emailImage" 
                        url="/resources/email.png"/>
                     <webuijsf:textField id="emailTextField"/>
                     <webuijsf:image id="phoneImage" 
                        url="/resources/phone.png"/>
                     <webuijsf:textField id="phoneTextField"/>
                  </h:panelGrid>
                  <webuijsf:image id="publicationsImage" 
                     style="position: absolute; left: 24px; top: 216px" 
                     url="/resources/publications.png"/>
                  <webuijsf:staticText id="publicationText" 
                     style="left: 216px; top: 216px; position: absolute" 
                     text="Which book would you like information about?"/>
                  <webuijsf:dropDown id="booksDropDown" items=
                     "#{WebComponents.booksDropDownDefaultOptions.options}"
                     style="position: absolute; left: 24px; top: 240px"/>
                  <webuijsf:hyperlink id="deitelHyperlink" 
                     style="position: absolute; left: 24px; top: 264px"
                     text="Click here to learn more about our books" 
                     url="http://www.deitel.com"/>
                  <webuijsf:image id="osImage" style="left: 24px; 
                     top: 312px; position: absolute" 
                     url="/resources/os.png"/>
                  <webuijsf:radioButtonGroup id="osRadioButtonGroup" 
                     items="#{WebComponents.
                        osRadioButtonGroupDefaultOptions.options}" 
                     style="left: 24px; top: 336px; position: absolute"/>
                  <webuijsf:button id="registerButton" style="left: 359px;
                     top: 456px; position: absolute; width: 96px" 
                     text="Register"/>
               </webuijsf:form>
            </webuijsf:body>
         </webuijsf:html>
      </webuijsf:page>
   </f:view>
</jsp:root>

<!-- 
********************************************************************** 
* (C) Copyright 1992-2009 by Deitel & Associates, Inc. and           *
* Pearson Education, Inc. All Rights Reserved.                       *
*                                                                    *
* DISCLAIMER: The authors and publisher of this book have used their *
* best efforts in preparing the book. These efforts include the      *
* development, research, and testing of the theories and programs    *
* to determine their effectiveness. The authors and publisher make   *
* no warranty of any kind, expressed or implied, with regard to      *
* these programs or to the documentation contained in these books.   *
* The authors and publisher shall not be liable in any event for     *
* incidental or consequential damages in connection with, or         *
* arising out of, the furnishing, performance, or use of these       *
* programs.                                                          *
********************************************************************** 
-->
