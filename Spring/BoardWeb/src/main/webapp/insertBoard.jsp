<%@page contentType="text/html; charset=EUC-KR"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>새 글 등록</title>
</head>
<body>
<center>
<h1>글 등록</h1>
<!-- Model 1 -->
<!-- <a href="logout_proc.jsp">Log-out</a> -->
<!-- Model 2 -->
<a href="logout.do">Log-out</a>
<hr>
<!-- Model 1 -->
<!-- <form action="insertBoard_proc.jsp" method="post"> -->
<!-- Model 2 -->
<form action="insertBoard.do" method="post">
<table border="1" cellpadding="0" cellspacing="0">
	<tr>
		<td bgcolor="orange" width="70">제목</td>
		<td align="left"><input type="text" name="title" /></td>
	</tr>
	<tr>
		<td bgcolor="orange">작성자</td>
		<td align="left"><input type="text" name="writer" size="10" /></td>
	</tr>
	<tr>
		<td bgcolor="orange">내용</td>
		<td align="left"><textarea name="content" rows="10" cols="40"></textarea></td>
	</tr>
	<tr>
		<td colspan="2" align="center"><input type="submit" value=" 새글 등록 " /></td>
	</tr>
</table>
</form>
<hr>
<a href="getBoardList.jsp">글 목록 가기</a>
</center>
</body>
</html>